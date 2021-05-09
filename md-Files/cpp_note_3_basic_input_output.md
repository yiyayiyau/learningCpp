# Basic Input/Output in C++

## 单词
primitive 原始

device 设备

respectively 分别

insertion operator 插入运算符 <<

synonymous 同义的

directive 指令

portion 一部分

desired number 所需数量

simultaneously 同时

omitted 省略

deliberately 故意

## 头文件
* iostream: cin, cout, cerr
	* cerr: 不存储在缓冲区中的报错
	* clog: 存储在缓冲区中的报错
* iomanip: 用于操纵流, 包含 setw, setprecision
* fstream: 文件流，处理从文件读取或写入数据


```c++
#include <iostream>
int main()
{
	cerr << "An error occured";
	return 0;
}
```

## Preprocessor 预处理器
以井号键开始
预处理器指令有四种主要类型:
* Macros 宏后面没有分号
```c++
#include <iostream>
#define LIMIT 5
#define AREA(l,b) (l*b)
int main()
{
	for (int i = 0; i < LIMIT; i++){
		std::cout << i << "\n";
	}
	int l1 = 10, l2=5. area;
	area = AREA(l1,l2);
	return 0;
}
```
* File inclusion 包含文件
	* 头文件或标准文件 #include <....>
	* 用户定义的文件 #include "...."
* Conditional Compilation 条件编译, 如果满足条件则编译，否则跳过
```c++
#ifdef macor_name
	statement1;
	statement2;
	...
	statementN;
#endif
```
* Other directives 其他指令
	* #undef 取消定义的宏
	* #pragma Directive: #pragma startup 和 #pragma exit, 前者仅在main函数前开始运行，后者j仅在return前运行。pragma不在gcc中工作 
	* #pragma warn Directive: 用于在编译过程中不显示警告信息 #pragma warn -rvl 本应该返回一个值; #pragma warn -par 函数本应该给参数; # pragma warn -rch 代码不可访问时的警告(例如在return之后的代码)
```c++
#undef LIMIT

#include <stdio.h>
void func1();
void func2();
// with pragma
#pragma startup func1
#pragma exit func2
// without pragma
//void __attribute__((constructor)) func1();
//void __attribute__((constructor)) func2();
void func1(){printf("Inside func1\n");}
void func2(){printf("Inside func2\n");}
int main(){
	void func1();
	void func2();
	printf("Inside main\n");
	return 0;
}

// output: 
//Inside func1
//Inside main
//Inside func2

```

## Operators 运算符

* 算术运算符: + - * / % ++ --, 后两者也成为一元运算符Unary Operators
* 关系运算符: == >= <= 
* 逻辑运算符: && ||
* 按位运算符: & | ^
* 分配运算符: = += -= /= 
* 其他: sizeof() 逗号 三元运算符 A?B:C

## Loops 循环

* for 和 while, 事先知道使用次数用for，不知循环次数但已知中止条件用while
* do-while, 至少执行一次用do-while
```c++
// 
for (initialization;Condition;updation){
	...
}
while(Condition){
	...
}
do{
	...
}while(Condition)
```

# Decision making
* if, if-else
* break
* continue
* goto 会使程序复杂化，尽量避免使用。
* return 
* switch
```c++
if(Condition){

}
else{

}
//
if(Condition){

}else if(Condition){

}else{

}
```
```c++
#include <iostream>
using namespace std;
void printNumbers(){
	int n=1;
label:
	cout << n << " ";
	n++;
	if(n<=10)
		goto label;
}
int main(){
	printNumbers();
	return 0;
}
//output: 1 2 3 4 5 6 7 8 9 10
```

```c++
switch(n)
{
	case 1:
		...
		break;
	case 2:
		...
		break;
	default:
		...
}
```

## 检查编译的版本
sizeof(size_t) 如果是8，那就是64位的编译，如果是4，是32位。

## Funtions
* 声明
```c++
int max(int, int);
int *swap(int*, int);//参数位一个pointer，一个int，返回一个整数的pointer 
```
```c++
#include <iostream>
void fun(int *ptr)
{
	*ptr = 30;
}
int main(){
	int x = 20;
	fun(&x);
	cout << "x= " << x;
	return 0;
}
// output: x= 30
```
* 由void声明的无返回函数，也可以有return; 但不能有任何返回值。
* C语言中，不可以返回arrays和functions, 但是可以返回他们的指针。
* **C**中，空的参数意味着这个函数可以在被调用时使用任何参数，**void fun()**, 声明无参数函数可以使用**void fun(void)**; **C++** 中，void fun()和void fun(void)**是一样的**
* 主函数有两种形式 
* C中，计算参数的顺序是取决于编译器的。
* C中，参数总是通过值来传递的pass by value，pass by reference是C通过显示传递指针值来模拟的。
* C中，函数名实际上是这个函数的指针变量。printf("%d",main); 得出的是主函数的地址。
* C中，... 在参数的位置时表示自变量的数量可变。
```c++
int main(){ ... return 0;}
//或者
int main(int argc, char* const argv[]){
	...
	return 0;
}
```

### 输入数量不确定
```c
#include <stdarg.h>
#include <stdio.h>
int min(int arg_count, ...)
{
	int i, min, a;
	va_list ap;
	va_start(ap, arg_count);
	// va_arg 是宏，每调用一次就会往后走一次，第一次调用是第一个输入
	min = va_arg(ap, int);
	for(i = 2; i<=arg_count; i++)
	{
		if((a = va_arg(ap, int)) < min)
			min = a;
	}
	va_end(ap);
	return min;
}
int main(){
	int cout = 5;
	printf("Minimun value is %d", min(cout, 12, 23, 34, 45, 56));
	//getchar();//从键盘输入一个字符
	return 0;
}

```

### 函数指针
```c
#include <stdio.h>
int main()
{
	void demo();
	void (*fun)();
	fun = demo;
	(*fun)();//1. call
	fun();//2. call
	return 0;
}
void demo(){
	printf("Colo ");
}
//output: Colo Colo
```
### extern, static
extern 用于全局变量，函数本事就是全局的，所以在函数前添加extern没有任何作用。(也不报错)
对静态函数的访问仅限于声明他们的文件，在函数前面添加static，将把全局的函数变为仅限于声明它的文件中访问

### function prototype 函数原型
函数原型告诉编译器有关函数采用的参数数量，参数的数据类型和函数返回类型的信息。

```c
#include <errno.h>
#include <stdio.h>
#include <string.h> // strerror的函数原型保存在这里，当不包含该头文件时，在x86_64上会报错
int main(int argc, char *argv[]){
	FILE *fp;
	fp = fopen(argv[1], "r");
	if(fp==NULL){
		fprint(stderr, "%s\n", strerror(errno));
		return errno;
	}
	printf("file exist\n");
	fclose(fp);
	return 0;
}
```

## Arrays

## Strings

## Pointers

## References

## OOP