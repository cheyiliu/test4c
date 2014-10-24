（1）首先生成*.o文件，输入gcc -c test.c -o test.o
（2）利用ar命令生成静态库，输入ar rc libtest.a test.o

use it
（1）首先输入gcc hello.c -o hello ./libtest.a

（2）输入./hello，验证生成的执行文件是否正确
