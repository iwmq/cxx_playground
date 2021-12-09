See https://taskflow.github.io/taskflow/index.html.

How to build Taskflow
---
1. Download Taskflow, and extract it to a directory (in this case, `C:\dev\taskflow\taskflow-3.2.0`).
2. Config Taskflow: `cd build`, then `cmake .. -G "MinGW Makefiles" -D CMAKE_INSTALL_PREFIX=c:\dev\taskflow\devel`.
3. Build Taskflow: `cmake --build .`.
4. Install Taskflow: `cmake --install .`.

NOTE: Taskflow is said to be a `Header only` library. However, it can be built.