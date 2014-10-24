如果我们想要生成动态库，要做的工作其实非常简单，输入gcc -shared -fPIC -o libtest.so test.c即可。

use it
输入gcc hello.c -o  hello ./libtest.so。然后输入./hello
