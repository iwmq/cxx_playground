This is a small project for demostrating c++ usage.

How to install?
---
- On Linux, use the system package manager to install cmake and gcc.
- On Windows, download cmake from `https://cmake.org/`, and MinGW from `https://github.com/brechtsanders/winlibs_mingw/releases/`


How to use?
---

1. Create and enter a build directory: `mkdir build && cd build`
2. Invoke cmake: `cmake ..` on Linux, `cmake .. -G "MinGW Makefiles"` on Windows
3. Build: `make` on Linux, `mingw32-make` on Windows

Know Issues
---
- Boost is not easily usable on Windows

Useful link: https://theboostcpplibraries.com/