## CCraft
CCraft is a clone of Minecraft written in C99, without a game engine. It allows for extensive modding and portability. If GLFW supports a platform, CCraft requires little modification to support it as well.

## Building
Windows users will need to install (CMake)[https://cmake.org/download] and (MinGW-w64)[https://github.com/niXman/mingw-builds-binaries/releases/latest]
Linux/BSD users will need to install `cmake gcc glu-devel libXcursor-devel libXi-devel libXinerama-devel libXrandr-devel libxkbcommon-devel make mesalib-devel pkg-config wayland-devel wayland-protocols`

After all dependencies are installed, run the following commands
```
git clone --recurse-submodules https://github.com/Duccy8502/CCraft.git
cd CCraft
```
If you are on Windows run
```
mingw32-make
```
If you are on Linux/BSD run
```
make
```
