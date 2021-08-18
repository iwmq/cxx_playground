How to build Eigen3 on Windows?
------------
1. Download eigen-3.4.0, unpack it to ` C:/Apps/eigen/eigen-3.4.0/`;
2. cd `C:/Apps/eigen/eigen-3.4.0/`;
3. run `mkdir build` and `cd build`;
4. run `cmake .. -G "MinGW Makefiles"`;

Note: No need to use make, as Eigen is a head-only library.