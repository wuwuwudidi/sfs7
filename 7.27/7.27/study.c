#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//计算器
void menu()
{
	printf("*****************\n");
	printf("**1add   2sub****\n");
	printf("**3mul   4div****\n");
	printf("*****0 exit *****\n");
	printf("*****************\n");
	printf("*****************\n");


}
int ADD(int x, int y)
{

	return x + y;
}
int sub(int x, int y)
{

	return x - y;
}int mul(int x, int y)
{

	return x *y;
}
int div(int x, int y)
{

	return x / y;
}
//int main()//函数指针数组的用途 --转移表 
//{
//	int x = 0;
//	int y = 0;
//	int input = 0;
//	int(*pfarr[])(int, int) = {0,ADD,sub,mul,div};
//	do
	/*{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		if (input >= 1 && input <= 4)
		{
			printf("请输入数字\n");
			scanf("%d%d", &x, &y);
			printf("%d\n",pfarr[input](x, y));
		}
		else if (input == 0)
		{
			printf("退出\n");
		}
		else 
		{
			printf("输入错误请重新输入\n");
		}

	} while(input);


	return 0;

}*/
//回调函数
void cacls(int(*pf)(int,int))
{
	int x = 0;
	int y = 0;
	printf("请输入数字\n");
	scanf("%d%d", &x, &y);
	printf("%d\n", pf(x, y));

}

//int main()
//{
//	
//	int input = 0;
//	do
//	{
//	menu();
//	printf("请选择：>");
//	scanf("%d", &input);
//	switch (input)
//	  {
//	case 1:
//		cacls(ADD);
//		break;
//	case 2:
//		cacls(sub);
//		break;
//
//	case 3:
//		
//		cacls(mul);
//		break;
//
//	case 4:
//		cacls(div);
//		break;
//
//	case 0:
//		printf("退出\n");
//		break;
//	default:
//		printf("输入错误重新输入\n");
//
//	  }
//	}while (input);
//	return 0;
//}
//int (*pfarr[4])(int,int)//pfarr是一个数组,函数指针的数组
//int (*(*ppfarr)[4])(int,int)=&pfarr //ppfarr 是一个指向函数指针数组的指针，指针指向4个元素，指向的数组的每一个元素的类型是一个函数指针 int(*)(int,int)
//回调函数

//
//void print(char * str)
//{
//	printf("hehe %s", str);
//}
//void test(void(*p)(char*str))
//{
//	printf("hehe\n");
//		p("bit");
//
//}
//int main()
//{
//	test(print);
//
//	return 0;
//} 
//void * 类型的指针 可以接受任意类型的地址 不能进行解引用操作 不能进行+-整数的操作
//

struct Stu
{
	char name; 
	int age;
};
int com_struct_age(const void*e1, const void*e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;

}

int com_struct_name(const void*e1, const void*e2)
{
	return strcmp(((struct Stu*)e1)->name,((struct Stu*)e2)->name);

}
int com_float(const void*e1,const void*e2)

{
	if (*(float*)e1 == *(float*)e2)
	{
		return 0;
	}
	else if (*(float*)e1 > *(float*)e2)
	{
		return 1;
	}
	else if (*(float*)e1 < *(float*)e2)
	{
		return -1;
	}

	
}
int com_int(const void*e1,const void *e2)
{
	return *(int*)e1 - *(int*)e2;
}
void test3()
{
	struct Stu s[3] = { { "zhangsan", 20 }, { "lisi", 10 }, { "wangwu", 30 } };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), com_struct_age);
	qsort(s, sz, sizeof(s[0]), com_struct_name);

}
void test2()
{
	float f[] = { 9.0, 8.0, 7.0, 6.0, 5.0, 4.0 };
	int sz = sizeof(f) / sizeof(f[0]);
	qsort(f, sz, sizeof(f[0]), com_float);
	int j = 0;
	for (j = 0; j < sz ; j++)
	{
		printf("%f\n", f[j]);
	}
}
void test1()
{
	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), com_int);
	int j = 0;
	for (j = 0; j < sz; j++)
	{
		printf("%d\n", arr[j]);
	}
}
int main()
{
	tese1();
	tset2();
	test3();
	return 0;
}