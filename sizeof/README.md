### the output is below on my 64 bit pc

```
housy@housy-desktop:~/github/test4c/sizeof$ ./main 

---------sizeof 类------
sizeof(class_c1) = 24
sizeof(class_c2) = 32

---------sizeof 基本类型------
sizeof(char)   = 1
sizeof(short)  = 2
sizeof(int)    = 4
sizeof(long)   = 8
sizeof(float)  = 4
sizeof(double) = 8

---------sizeof 基本类型指针------
sizeof(char*)   = 8
sizeof(short*)  = 8
sizeof(int*)    = 8
sizeof(long*)   = 8
sizeof(float*)  = 8
sizeof(double*) = 8

---------sizeof 结构体，涉及结构体对齐的知识点------
sizeof(struct struct_s1) = 24
sizeof(struct struct_s2) = 16
sizeof(struct struct_s3) = 14
sizeof(struct s1) = 16
sizeof(struct s2) = 24
sizeof(struct s3) = 24
sizeof(struct s4) = 24
sizeof(demo_type) = 8

---------地址 of 结构体变量------
address of ss2   = 0x7fffb5ed2770
address of ss2.a = 0x7fffb5ed2770
address of ss2.b = 0x7fffb5ed2771
address of ss2.c = 0x7fffb5ed2774
address of ss2.d = 0x7fffb5ed2778

---------sizeof 稍微复杂点的例子------
8
144
48
8
8

---------sizeof 函数参数------
sizeof(arg)   = 8
housy@housy-desktop:~/github/test4c/sizeof$ 


```
