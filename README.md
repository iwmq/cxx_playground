This is a small project for demostrating c++ usage.

How to install?
---
- On Linux, use the system package manager to install cmake and gcc.
- On Windows, download cmake from `https://cmake.org/`, and MinGW from `https://github.com/brechtsanders/winlibs_mingw/releases/`

Build Boost On Windows
--------
1. Download Boost, and extract it to a directory (in this case, `C:\Apps\boost\boost_1_77_0`)
2. Build Boost's build tool `b2`: `cd tools\build`, then `bootstrap.bat gcc`
3. Build Boost itself: In boost's root directory, run `tools\build\b2.exe install toolset=gcc --prefix=c:\apps\boost\devel`

On my laptop with Intel Core i5-10210U CPU and 12 GiB 2400MHz RAM, the second step takes about 50 seconds,
and the third step takes about 23.5 minutes.

How to use?
---

1. Create and enter a build directory: `mkdir build && cd build`
2. Invoke cmake: `cmake ..` on Linux, `cmake .. -G "MinGW Makefiles"` on Windows
3. Build: `make` on Linux, `mingw32-make` on Windows, or simply `cmake --build .`

Useful link: https://theboostcpplibraries.com/