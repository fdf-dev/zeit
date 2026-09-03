Name:           zeit
Version:        0.6.95
Release:        1%{?dist}
Summary:        Qt frontend for crontab and at
License:        GPL-3.0-or-later
URL:            https://github.com/fdf-dev/zeit
Source0:        %{name}-%{version}.tar.gz

BuildRequires:  cmake
BuildRequires:  extra-cmake-modules
BuildRequires:  gcc-c++
BuildRequires:  make
BuildRequires:  qt6-qtbase-devel
BuildRequires:  qt6-qttools-devel
Requires:       at
Requires:       cronie
Requires:       libnotify
Requires:       mpv

%description
Zeit is a Qt graphical frontend for managing user crontab entries and at jobs.

%prep
%autosetup

%build
%cmake -DWITH_QT6=ON -DBUILD_TESTS=OFF
%cmake_build

%install
%cmake_install

%files
%license Copying
%doc Readme.md Changelog
%{_bindir}/zeit
%{_libdir}/libcrontab.so.*
%{_datadir}/applications/zeit.desktop
%{_datadir}/icons/hicolor/32x32/apps/zeit.xpm
%{_datadir}/zeit/translations/*.qm

%changelog
* Thu Sep 03 2026 fdf-dev <fdf-dev@users.noreply.github.com> - 0.6.95-1
- Add initial RPM package
