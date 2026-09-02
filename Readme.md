# Zeit project
 Qt frontend to `crontab` and `at`

### Features: ###
* Add, edit and delete `crontab` tasks
* Add, edit and delete environment variables for `crontab`
* Add and delete `at` commands
* Alarms and Timers
* Optional root actions, PolKit support (KF5Auth and KF5CoreAddons needed)

### Build dependencies ###
You need Git, CMake 3.16 or newer, a C++ compiler, Qt 6 Base,
Qt 6 Tools and Extra CMake Modules. KF6Auth and KF6CoreAddons are
optional and enable PolKit root actions.

Qt 5 remains available as a compatibility option by configuring with
`-DWITH_QT6=OFF` and installing `qt5-qtbase-devel` and `qt5-qttools`.

On Fedora:

```bash
sudo dnf install git cmake gcc-c++ qt6-qtbase-devel qt6-qttools-devel \
	extra-cmake-modules kf6-kauth-devel kf6-kcoreaddons-devel \
	cronie at libnotify mpv
```

On Debian or Ubuntu:

```bash
sudo apt install git cmake g++ qt6-base-dev qt6-tools-dev \
	extra-cmake-modules libkf6auth-dev libkf6coreaddons-dev \
	cron at libnotify-bin mpv
```

On Arch Linux:

```bash
sudo pacman -S --needed git cmake base-devel qt6-base qt6-tools \
	extra-cmake-modules kauth kcoreaddons cronie at libnotify mpv
```

The runtime commands are `crontab` and, optionally, `at`. The application
also uses `libnotify` and `mpv` for notifications and audio playback.

### Download the source ###

```bash
git clone https://github.com/fdf-dev/zeit.git
cd zeit
```

### Build and run ###
```bash
cmake -S . -B build \
	-DCMAKE_BUILD_TYPE=Release \
	-DCMAKE_INSTALL_PREFIX=/usr/local
cmake --build build --parallel
```

### Installation on Fedora ###

```bash
sudo cmake --install build
sudo ldconfig
hash -r
/usr/local/bin/zeit
```

The installation also adds `zeit.desktop` and the `zeit` icon to the
application menu. If the menu does not refresh immediately, run:

```bash
update-desktop-database /usr/local/share/applications 2>/dev/null || true
```

### Create a desktop shortcut ###

To place a Zeit launcher directly on the desktop, run this as your normal
user after installing the application:

```bash
DESKTOP_DIR="$(xdg-user-dir DESKTOP 2>/dev/null || printf '%s\n' "$HOME/Desktop")"
mkdir -p "$DESKTOP_DIR"
cp /usr/local/share/applications/zeit.desktop "$DESKTOP_DIR/Zeit.desktop"
chmod +x "$DESKTOP_DIR/Zeit.desktop"
gio set "$DESKTOP_DIR/Zeit.desktop" metadata::trusted true 2>/dev/null || true
```

The shortcut uses the installed executable and icon paths. If the file does
not appear immediately, log out and in again or refresh the desktop.

### Install for the current user ###

This option does not require `sudo` and installs the application and its
desktop entry under `~/.local`:

```bash
cmake -S . -B build-user \
	-DCMAKE_BUILD_TYPE=Release \
	-DCMAKE_INSTALL_PREFIX="$HOME/.local"
cmake --build build-user --parallel
cmake --install build-user
mkdir -p "$HOME/.local/share/applications"
update-desktop-database "$HOME/.local/share/applications" 2>/dev/null || true
```

Add the user executable directory to the shell path if necessary:

```bash
echo 'export PATH="$HOME/.local/bin:$PATH"' >> "$HOME/.bashrc"
source "$HOME/.bashrc"
zeit
```

### Screenshot ###
![Screenshot of the Zeit app](https://raw.githubusercontent.com/loimu/zeit/master/assets/screenshot.png)

### Installation on Ubuntu ###
```bash
# stable releases
sudo add-apt-repository ppa:blaze/main
sudo apt update
sudo apt install zeit

# development snapshots
sudo add-apt-repository ppa:blaze/dev
sudo apt update
sudo apt install zeit
```
