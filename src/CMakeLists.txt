cmake_minimum_required(VERSION 3.22)
project(SRC_LIB)
# 设置动态库的源文件以及头文件目录
aux_source_directory(./ SRC)
include_directories(${HEAD_PATH})
# 添加动态库或者共享库
add_library(${SRC_LIB} OBJECT ${SRC})