This is a small project for demostrating c++ usage.

How to install?
---
- On Linux, use the system package manager to install cmake and gcc.
- On Windows, download cmake from `https://cmake.org/`, and MinGW from `https://github.com/brechtsanders/winlibs_mingw/releases/`.

Build Boost On Windows
--------
1. Download Boost, and extract it to a directory (in this case, `C:\dev\boost\boost_1_80_0`).
2. Build Boost's build tool `b2`: `cd tools\build`, then `.\bootstrap.bat gcc`.
3. Build Boost itself: In boost's root directory, run `tools\build\b2.exe install toolset=gcc --prefix=c:\dev\boost\devel`.

NOTE: It is extremely important to run b2.exe in the boost root directory, otherwise it will fail to compile boost. 

On my laptop with Intel Core i5-10210U CPU and 12 GiB 2,400 MHz RAM, for Boost 1.78, the second step takes about 50 seconds,
and the third step takes about 23.5 minutes.

For Boost 1.80, the third step takes 52 minutes.

On Windows Powershell, to measure time for the second command, run:
```
Measure-Command -Expression { tools\build\b2.exe install toolset=gcc --prefix=c:\dev\boost\devel | Out-Default }
```

How to use?
---

1. Create and enter a build directory: `mkdir build && cd build`
2. Invoke cmake: `cmake ..` on Linux, `cmake .. -G "MinGW Makefiles"` on Windows
3. Build: `make` on Linux, `mingw32-make` on Windows, or simply `cmake --build .`

Useful link: https://theboostcpplibraries.com/