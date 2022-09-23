### 设置C++标准为 C++ 11
set(CMAKE_CXX_STANDARD 11)

### dll直接连接到exe中
set(CMAKE_EXE_LINKER_FLAGS "-static")

### 使用 CMake 创建项目时，应该指定支持的最低版本
cmake_minimum_required (VERSION 3.10.0)

### 项目名称
project (demo) #则 `${PROJECT_NAME}` 的值为 demo

### 指定应从指定的源文件构建可执行文件
add_executable(${PROJECT_NAME} main.c)

### 指定目录下所有的源文件存储在一个变量中
aux_source_directory(dir var) # . 就是当前目录
+ 第一个参数dir是指定目录
+ 第二个参数var是用于存放源文件列表的变量。

### set命令去新建变量来存放需要的源文件
set( SOURCES ./main.c ./testFunc1.c ./testFunc.c)

### 使用 GLOB 命令使用通配符模式匹配查找文件
file(GLOB SOURCES "src/*.c")  
add_executable(${PROJECT_NAME} ${SOURCES})

### 向工程添加多个指定头文件的搜索路径，路径之间用空格分隔
include_directories (test_func test_func1)

### 对于现代的CMake，不建议对源代码使用变量，通常直接在add_xxx函数中声明源代码。也就是建议写成：
add_executable(${PROJECT_NAME} 
        src/testFunc.c
        src/testFunc1.c
        src/main.c
)

### 当你有不同的头文件目录时，可以使用target_include_directories()函数让编译器知道它们编译此目标时，会将这些目录添加到带有-i标志的编译指令中，例如-i/directory/path
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)


### 这个好 , 是在 build/bin 中生成 exe 文件
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
