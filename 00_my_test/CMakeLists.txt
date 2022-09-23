cmake_minimum_required(VERSION 3.10.0)
project(00_my_test)
set(CMAKE_EXE_LINKER_FLAGS "-static")

# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) #不好 , 我要在 build 中生成
# # ${PROJECT_SOURCE_DIR} 是他妈的 这个 CMakeLists.txt 所在的目录

# set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin) #不好 , 我要在 build 中生成
# # 这个更操蛋 ${CMAKE_SOURCE_DIR} 是他妈的 主 CMakeLists.txt 所在的目录

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin) #这个好 , 是在 build/bin 中生成

add_executable(${PROJECT_NAME} main.cpp)
