# Zeit project
 Qt frontend to `crontab` and `at`

### Features: ###
* Add, edit and delete `crontab` tasks
* Add, edit and delete environment variables for `crontab`
* Add and delete `at` commands
* Alarms and Timers
* Optional root actions, PolKit support (KF5Auth and KF5CoreAddons needed)

### Build dependencies ###
Extra CMake Modules, CMake 3.16 or newer, Qt 6 Base, Qt 6 Tools,
KF6Auth (optional), KF6CoreAddons (optional)

On Fedora, install the build dependencies with:

```bash
sudo dnf install cmake gcc-c++ qt6-qtbase-devel qt6-qttools-devel \
	extra-cmake-modules kf6-kauth-devel kf6-kcoreaddons-devel \
	cronie at libnotify mpv
```

Qt 5 remains available as a compatibility option by configuring with
`-DWITH_QT6=OFF` and installing `qt5-qtbase-devel` and `qt5-qttools`.

### Runtime dependencies ###
On Fedora: `cronie`, `at`, `libnotify`, `mpv`

### Build and run ###
```bash
cmake -S . -B build \
	-DCMAKE_BUILD_TYPE=Release \
	-DCMAKE_INSTALL_PREFIX=/usr/local
cmake --build build --parallel
/usr/local/bin/zeit
```

### Installation on Fedora ###

```bash
sudo cmake --install build
sudo ldconfig
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
