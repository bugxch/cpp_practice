cmake_minimum_required(VERSION 3.22)
project(TEST)

include_directories(
	${HEAD_PATH}  # 动态库头文件目录
	${CMAKE_CURRENT_SOURCE_DIR}/third_party/googletest/googletest/include # 静态库头文件目录
	)
# 设置可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${EXEC_PATH})
# 生成可执行文件
aux_source_directory(./ SRC)
add_executable(${APP_NAME} ${SRC})

# 链接gtest静态库
set(GTEST_LIB gtest gtest_main)
target_link_libraries(${APP_NAME} ${GTEST_LIB} ${SRC_LIB})