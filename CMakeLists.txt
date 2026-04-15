cmake_minimum_required(VERSION 3.28)
project(AlgorithmProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(AlgorithmProject
        src/大二下.cpp)

## 计算100MB的字节数
#math(EXPR stack_size "100 * 1024 * 1024")
## 设置栈大小
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,${stack_size}")