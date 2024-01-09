### 一、单向和双向链表实现
- 使用循环链表实现
- 侵入式链表

### 二、使用说明
- 1.只需要将list文件夹中的文件移动到自己的工程中即可
- 2.可参考test/singly_list_test.c和test/doubly_list_test.c中的测试代码使用

### 三、编译当前工程的示例
输出的可执行文件和静态库均在./build/out文件夹内
#### 3.1 cmake构建
Linux环境下

    mkdir build
    cd build
    cmake ..
    cmake --build .

Windows环境下，以MinGW64为例

    mkdir build
    cd build
    cmake -G "MinGW Makefiles" ..
    cmake --build .

#### 3.2 使用make构建

    make
