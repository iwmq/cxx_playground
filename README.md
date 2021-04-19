This is a small project for demostrating c++ usage.

How to install?
---
- On Linux, use the system package manager to install cmake and gcc.
- On Windows, download cmake from `https://cmake.org/`, and MinGW from `https://github.com/brechtsanders/winlibs_mingw/releases/`

Build Boost On Windows
--------
1. Download Boost, and extract it to a directory (in this case, `C:\Apps\boost\boost_1_76_0`)
2. Build Boost's build tool `b2`: `cd tools\build`, then `bootstrap.bat gcc`
3. Build Boost itself: In boost's root directory, run `tools\build\b2.exe install toolset=gcc --prefix=c:\apps\boost\devel`

How to use?
---

1. Create and enter a build directory: `mkdir build && cd build`
2. Invoke cmake: `cmake ..` on Linux, `cmake .. -G "MinGW Makefiles"` on Windows
3. Build: `make` on Linux, `mingw32-make` on Windows

Useful link: https://theboostcpplibraries.com/