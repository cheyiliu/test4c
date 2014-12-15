#include <stdio.h>
/*
 from http://blog.csdn.net/yanzi1225627/article/details/40518223

 最终输出结果如下：

 里面所有的判断都是相等，打印的两个值是2和5.

 原因如下：

 &a是数组的首地址，它的类型是int(*)[5]，因此+1是加的是数组个数的步长。
 指针加1要根据指针自身类型加上一定的值， 不同类型的指针+1之后增加的大小不同。
 因此&a + 1后指向的地址对数组来说是越界的，注意前面有个int(*)又强制将他转为int*了。
 因此计算*(ptr - 1)的时候，ptr是个int类型的指针，减一等于往左移动sizeof(int*)个字节，
 因此又指向a[4]了，他的值等于&a[4].

 为此杂家又对p4和p5作了验证，为啥结果p4会等于p5呢？原因就在于申请p3的时候对&a进行了强制类型转换，

 [cpp] view plaincopyprint?在CODE上查看代码片派生到我的代码片

 int *p3 = (int *)(&a);

 如果不加这个转换，是编译不过去的。加了转换之后p3等于p1也等于p2，
 他的类型跟另外两个一样都是int*类型的了，因此移动相同位后地址也是一样的。
 很多人纠结就纠结在&a、a、&a[0]，根本原因在于对&a进行了强制类型(int*)转换。
 */
int main(void) {
	int a[5] = { 1, 2, 3, 4, 5 };
	int *ptr = (int *) (&a + 1);
	int *p1 = a;
	int *p2 = &a[0];
	int *p3 = (int *) (&a);

	if (p1 == p2) {
		printf("p1 == p2\n");
	} else {
		printf("p1 != p2\n");
	}

	if (p1 == p3) {
		printf("p1 == p3\n");
	} else {
		printf("p1 != p3\n");
	}

	if (p2 == p3) {
		printf("p2 == p3\n");
	} else {
		printf("p2 != p3\n");
	}

	printf("%d %d\n", *(a + 1), *(ptr - 1));

	int *p4 = ++p1;
	int *p5 = ++p3;
	if (p4 == p5) {
		printf("p4 == p5\n");
	} else {
		printf("p4 != p5\n");
	}
	return 0;
}
