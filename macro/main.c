#define STR(s) # s
STR(hello 	world)

fputs(STR(strncmp("ab\"c\0d", "abc", '\4"') == 0) STR(:@\n), s);


#define showlist(...) printf(#__VA_ARGS__)
#define report(test, ...) ((test)?printf(#test):\
	printf(__VA_ARGS__))

showlist(The first, second, and third items.);
report(x>y, "x is %d but y is %d", x, y);


#define FOO(a) foo##a
FOO(bar)
FOO()


#define FOO(a, b, c) a##b##c
FOO(1,2,3)
FOO(1,2,)
FOO(1,,3)
FOO(,,3)


#define FOO(a, ...) a##__VA_ARGS__
FOO(1)
FOO(1,2,3,)



#define sh(x) printf("n" #x "=%d, or %d\n",n##x,alt[x])
#define sub_z  26
sh(sub_z)





#define x 3
#define f(a) f(x * (a))
#undef x
#define x 2
#define g f
#define t(a) a

t(t(g)(0) + t)(1);
/*
    先把g展开成f再替换到#define t(a) a中，得到t(f(0) + t)(1);。

    根据#define f(a) f(x * (a))，得到t(f(x * (0)) + t)(1);。

    把x替换成2，得到t(f(2 * (0)) + t)(1);。注意，一开始定义x为3，但是后来用#undef x取消了x的定义，又重新定义x为2。
    当处理到t(t(g)(0) + t)(1);这一行代码时x已经定义成2了，所以用2来替换。还要注意一点，现在得到的t(f(2 * (0)) + t)(1);中仍然有f，
    但不能再次根据#define f(a) f(x * (a))展开了，f(2 * (0))就是由展开f(0)得到的，这里面再遇到f就不展开了，
    这样规定可以避免无穷展开（类似于无穷递归），因此我们可以放心地使用递归定义，例如#define a a[0]，#define a a.member等。

    根据#define t(a) a，最终展开成f(2 * (0)) + t(1);。这时不能再展开t(1)了，因为这里的t就是由展开t(f(2 * (0)) + t)得到的，所以不能再展开了。
 */
1. t(t(f)(0) + t)(1);
2. t(f(0) + t)(1);
3. t(f(x * (0)) + t)(1);
4. t(f(2 * (0)) + t)(1);
5. f(2 * (0)) + t(1)



