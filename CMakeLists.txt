cmake_minimum_required(VERSION 3.22)
project(hada)

# 设置变量
set(EXEC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(HEAD_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 设置动态库名称
set(SRC_LIB leetcode)
set(APP_NAME my_test)

# 添加子目录
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(third_party/googletest)