c++ 学习笔记1
# Basic
* 静态类型的编程语言，在编译时类型检查。动态类在运行时类型检查。
* C++的组成: 核心语言，C++标准库，标准模板库STL
* 三字符组: 用来表示以前键盘上没有的字符,以两个问号开头。如果两个问号不想被替换: "...?""?..." 或 "...?\?..."
```c++
??= == 	#
??/ == 	\
??' == 	^
??( == 	[
??) == 	]
??! == 	|
??< == 	{
??> == 	}
??- == 	~
```
* 注释: #if 0 也可以实现注释的作用，可用于执行测试代码
```c++
#if 0
	...
#else
	...
#endif
```
* 数据类型: bool, char, int, float, double, void, wchar_t. wchar_t相当于 short int. typedef short int wchar_t;
* 类型修饰符: signed, unsigned, short, long
* 一个字节为8位，sizeof(int) unsigned int, signed int==4字节，char, unsigned char, signed char == 一个字节; short int, unsigned short int, signed short int == 2 个字节。	void 表示类型的缺失。
* 得到最大值或最小值
```c++
sizeof(bool) // 所占字节数
cout << (numeric_limits<bool>::max)();//最大值
cout << (numeric_limits<bool>::min)();//最小值
```
* 定义新类型
```c++
//模板typedef type newname;
typedef int feet;
feet distance;
```
* 枚举
```c++
//模板enum name { Value1[=0], Value2[=1]...} variable;
enum color {red,green,blue} c; //默认 red = 0, green = 1
c = blue;
enum color{red, green = 5, blue} c; // 默认red = 0, blue = 6
c = blue
```
* 24/5 == 4;
* 24.0/5.0 == 4.8
* 10%3 == 1
* int arr[2]; arr[3] arr[-2] 超出array的范围在编译时不会报错，但会有不符合期待的输出。
* int arr[2] = {1,2,3,4}; 在C中只有警告，但在C++会报错
* sizeof(int); 可以得到一个int的长度。
* void main() 不合法
* int main() 和 int main(void) 相比，后者指明main只能在没有任何参数的情况下使用。
* 在C语言中，void fun() 可以在有参数以及没有参数下成功运行; void fun(void) 只能在没有参数的时候运行
* 在C++中, void fun() 和 void fun(void) 一样，只能在没有参数的时候运行
* #pragma once 只编译一次; 可以避免由多次出现同一个编译对象导致的问题
* preprocessor预处理器，由编译器调用处理#开头的程序
* #include 包含的头文件经过预处理后将复制到当前文件中，<>表示预处理器将查看包含所有头文件的标准文件夹而""将查看当前文件夹/当前目录
* #define max 100 当使用define定义一个常数时，预处理器将搜索该常量并替换为此处定义的值。

```c
#include<stdio.h>
#define max 100
int main(){
	printf("max is %d", max);
	return 0;
}
// output : max is 100
```
* 宏不检查自变量的数据类型
```c
#include<stdio.h>
#define INCREMENT(x) ++x
int main(){
	char *ptr = "GeeksQuiz";
	int x = 10;
	printf("%s ", INCREMENT(ptr));
	printf("%d ", INCREMENT(x));
	return 0;
}
// output : eeksQuiz 11 // char 指针整体往左移
```
* 宏拓展之前不评估参数
```c
#include<stdio.h>
#define MULTIPLY(a,b) a*b
int main(){
	
	printf("%d ", MULTIPLY(2+3,3+5));
	return 0;
}
// output : 16// 2+3*3+5 not as 5*8
#include<stdio.h>
#define MULTIPLY(a,b) (a)*(b)
int main(){
	
	printf("%d ", MULTIPLY(2+3,3+5));
	return 0;
}
// output : 40// as 5*8
```
* Token-Pasting Operator: concatenat tokens
```c
#include<stdio.h>
#define merge(a,b) a##b
int main(){
	printf("%d ", merge(12,34));
	return 0;
}
// output: 1234
```
* 转换为字符串
```c
#include<stdio.h>
#define get(a) #a
int main(){
	printf("%s ", get(GeeksQuiz));
	return 0;
}
// output: GeeksQuiz//被转换为字符串
```
* 宏可以写为多行，每行最后加 \, 最后一行不需要
```c
#include<stdio.h>
#define PRINT(i, limit) while(i<limit)\
						{\
							printf("GeeksQuiz ");\
							i++;\
						}
int main(){
	int i = 0;
	PRINT(i, 3);
	return 0;
}
// output: GeeksQuiz GeeksQuiz GeeksQuiz
```
* 避免使用带参数的宏，因为有时会有问题，首选内联函数inline functions
```c
#include <stdio.h>
#define square(x) x*x
int main()
{
	int x = 36/square(6);
	printf("%d", x);
	return 0;
}
// output: 36 // 36/6*6 not as 36/(6*6)
#include <stdio.h>
static inline int square(int x){return x*x;}
int main()
{
	int x = 36/square(6);
	printf("%d", x);
	return 0;
}
// output: 1
```
* 预处理器还支持if-else命令，通常用于条件编译
```c
int main()
{
#if VERBOSE >=2
	printf("Trace Message");
#endif
}
// output: 没有输出
```
* 头文件可能被多次直接或间接包含，可能导致重新声明变量的问题或重新声明函数的问题，可以使用**defined**,**ifdef**,**ifndef**来避免
* 一些标准宏可用于答应程序文件，编译日期，编译时间，行号
```c
#include <stdio.h>
int main()
{
	printf("Current File: %s\n", __FILE__);
	printf("Current Data: %s\n", __DATE__);
	printf("Current Time: %s\n", __TIME__);
	printf("Line Number: %d\n", __LINE__);
	return 0;
}
```
* 删除已经存在的宏 #undef MACRO_NAME
```c
#include <stdio.h>
#define LIMIT 100
int main()
{
	printf("%d", LIMIT);
	#undef LIMIT
	printf("%d", LIMIT); // 出现问题，因为已删除
	int LIMIT = 1000;
	printf("%d", LIMIT); // 1000
	return 0;
}
```

```c
#include <stdio.h>
float div(float, float);
#define div(x,y) x/y
int main()
{
	print("0.2f", div(10.0,5.0));
	#undef div
	print("0.2f", div(10.0,5.0));
	return 0;
	float div(float x, float y)
	{
		return y/x;
	}
}
//output: 2.00 0.50 // 通过宏定义的函数有更高的执行权，删除之后才会执行普通定义的函数
```

