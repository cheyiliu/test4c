这是一个简单的汇编文件，我们可以分两步进行编译。首先，输入 as -gstabs -o hello.o hello.s, 接着输入ld -o hello hello.o即可。为了验证执行文件是否正确，可以输入./hello验证一下。

housy@housy-desktop:~/github/test4c/assembly$ as -gstabs -o assembly.o assembly.s 
housy@housy-desktop:~/github/test4c/assembly$ ld -o assembly assembly.o
housy@housy-desktop:~/github/test4c/assembly$ ./assembly 
hello!
 
