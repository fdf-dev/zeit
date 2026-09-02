/* ========================================================================
*    Copyright (C) 2015-2024 Blaze <blaze@vivaldi.net>
*
*    This file is part of Zeit.
*
*    Zeit is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    Zeit is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with Zeit.  If not, see <http://www.gnu.org/licenses/>.
* ======================================================================== */

#include "config.h"

#include <unistd.h>
#include <QApplication>
#include <QHash>
#include <QSettings>
#include <QTranslator>

#include "mainwindow.h"

namespace {
class PortugueseTranslator : public QTranslator
{
public:
    PortugueseTranslator() {
        translations = {
            {QStringLiteral("&Help"), QStringLiteral("&Ajuda")},
            {QStringLiteral("&Tools"), QStringLiteral("&Ferramentas")},
            {QStringLiteral("&View"), QStringLiteral("&Exibir")},
            {QStringLiteral("&About"), QStringLiteral("&Sobre")},
            {QStringLiteral("&Add Entry"), QStringLiteral("&Adicionar entrada")},
            {QStringLiteral("&Quit"), QStringLiteral("&Sair")},
            {QStringLiteral("&Delete Entry"), QStringLiteral("&Excluir entrada")},
            {QStringLiteral("Delete Entry"), QStringLiteral("Excluir entrada")},
            {QStringLiteral("&Modify Entry"), QStringLiteral("&Modificar entrada")},
            {QStringLiteral("&Timer"), QStringLiteral("&Temporizador")},
            {QStringLiteral("&Alarm"), QStringLiteral("&Alarme")},
            {QStringLiteral("&Periodic Tasks"), QStringLiteral("&Tarefas periódicas")},
            {QStringLiteral("&Environment Variables"), QStringLiteral("&Variáveis de ambiente")},
            {QStringLiteral("&Nonperiodic Commands"), QStringLiteral("Comandos &não periódicos")},
            {QStringLiteral("&System Mode"), QStringLiteral("Modo do &sistema")},
            {QStringLiteral("&Refresh"), QStringLiteral("&Atualizar")},
            {QStringLiteral("Show &Filter"), QStringLiteral("Mostrar &filtro")},
            {QStringLiteral("S&horten Text"), QStringLiteral("&Reduzir texto")},
            {QStringLiteral("To&ggle"), QStringLiteral("Alternar")},
            {QStringLiteral("Toggle Item"), QStringLiteral("Alternar item")},
            {QStringLiteral("&Copy Entry"), QStringLiteral("&Copiar entrada")},
            {QStringLiteral("Copy Entry"), QStringLiteral("Copiar entrada")},
            {QStringLiteral("&Language"), QStringLiteral("&Idioma")},
            {QStringLiteral("Automatic"), QStringLiteral("Automático")},
            {QStringLiteral("Portuguese (Brazil)"), QStringLiteral("Português (Brasil)")},
            {QStringLiteral("English"), QStringLiteral("Inglês")},
            {QStringLiteral("Filter…"), QStringLiteral("Filtrar…")},
            {QStringLiteral("Hide"), QStringLiteral("Ocultar")},
            {QStringLiteral("New Alarm"), QStringLiteral("Novo alarme")},
            {QStringLiteral("New Command"), QStringLiteral("Novo comando")},
            {QStringLiteral("New Timer"), QStringLiteral("Novo temporizador")},
            {QStringLiteral("New Task"), QStringLiteral("Nova tarefa")},
            {QStringLiteral("Edit Task"), QStringLiteral("Editar tarefa")},
            {QStringLiteral("New Variable"), QStringLiteral("Nova variável")},
            {QStringLiteral("Edit Variable"), QStringLiteral("Editar variável")},
            {QStringLiteral("Description:"), QStringLiteral("Descrição:")},
            {QStringLiteral("Command:"), QStringLiteral("Comando:")},
            {QStringLiteral("Now"), QStringLiteral("Agora")},
            {QStringLiteral("Reset"), QStringLiteral("Redefinir")},
            {QStringLiteral("Run at"), QStringLiteral("Executar às")},
            {QStringLiteral("Sound File:"), QStringLiteral("Arquivo de som:")},
            {QStringLiteral("Player:"), QStringLiteral("Reprodutor:")},
            {QStringLiteral("Every minute"), QStringLiteral("A cada minuto")},
            {QStringLiteral("Every hour"), QStringLiteral("A cada hora")},
            {QStringLiteral("Every day"), QStringLiteral("Todos os dias")},
            {QStringLiteral("Every week"), QStringLiteral("Toda semana")},
            {QStringLiteral("Every month"), QStringLiteral("Todo mês")},
            {QStringLiteral("Every weekday"), QStringLiteral("Todos os dias úteis")}
        };
    }

    QString translate(const char*, const char* source,
                      const char*, int) const override {
        return translations.value(QString::fromUtf8(source));
    }

private:
    QHash<QString, QString> translations;
};
}

int main(int argc, char *argv[])
{
    if(getuid() == 0)
        qFatal("User should not be root");
    bool showTrayIcon = false;
    if(argc > 1) {
        QByteArray arg = argv[1];
        if(arg == QByteArray("-t") || arg == QByteArray("--tray-icon")) {
            showTrayIcon = true;
        }
    }
    QApplication a(argc, argv);
    QApplication::setApplicationName(QStringLiteral("Zeit"));
    QApplication::setOrganizationName(QStringLiteral("zeit"));
    QApplication::setApplicationVersion(QStringLiteral(ZEIT_V));
    QSettings settings(QCoreApplication::organizationName(),
                       QCoreApplication::applicationName());
    const QString language = settings.value(QStringLiteral("General/language"),
                                             QStringLiteral("system")).toString();
    const QLocale locale = language == QLatin1String("system")
                               ? QLocale::system() : QLocale(language);
    const bool usePortuguese = language == QLatin1String("pt_BR")
                               || (language == QLatin1String("system")
                                   && locale.name().startsWith(QLatin1String("pt_BR")));
    QLocale::setDefault(locale);
    bool result;
    PortugueseTranslator portugueseTranslator;
    QTranslator translator;
    result = usePortuguese
                 ? a.installTranslator(&portugueseTranslator)
                 : translator.load(QApplication::applicationDirPath() +
                             QLatin1String("/../share/zeit/translations/") +
                             QLatin1String("zeit_") +
                             locale.name() + QLatin1String(".qm"));
    if(!usePortuguese)
        a.installTranslator(&translator);
    QTranslator libTranslator;
    if(language != QLatin1String("pt_BR")) {
        result &= libTranslator.load(QApplication::applicationDirPath() +
                                 QLatin1String("/../share/zeit/translations/") +
                                 QLatin1String("crontablib_") +
                                 locale.name() + QLatin1String(".qm"));
        a.installTranslator(&libTranslator);
    }
    Q_UNUSED(result)
    MainWindow w;
    w.show();
    if(showTrayIcon)
        w.showTrayIcon();
    return a.exec();
}
