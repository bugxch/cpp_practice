cmake_minimum_required(VERSION 3.22)
project(hada CXX)

# 设置变量
set(EXEC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build)
set(HEAD_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

# 设置动态库名称
set(SRC_LIB leetcode)
set(APP_NAME my_test)

# 添加子目录
add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(third_party/googletest)