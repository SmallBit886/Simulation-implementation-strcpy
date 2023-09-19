#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//****************************************************//
//如何写出好（易于调试）的代码
//1. 代码运行正常
//2. bug很少			
//3. 效率高			
//4. 可读性高			
//5. 可维护性高			
//6. 注释清晰			
//7. 文档齐全	
//****************************************************//	
//常见的coding技巧：
//1. 使用assert
//2. 尽量使用const
//3. 养成良好的编码风格
//4. 添加必要的注释
//5. 避免编码的陷阱
//****************************************************//
//void my_strcpy(char* dest, char* src)	//模拟实现库函数：strcpy
//{
//	while (*src != '\0')
//	{
//		*dest = *src;
//		src++;
//		dest++;
//	}
//	*dest = *src;
//}
////代码优化1
//void my_strcpy(char* dest, char* src)	//模拟实现库函数：strcpy
//{
//	while (*src != '\0')
//	{
//		*dest++ = *src++;
//	}
//	*dest = *src;
//}
////代码优化2
//void my_strcpy(char* dest, char* src)	//模拟实现库函数：strcpy
//{
//	while (*dest++ = *src++)
//	{
//		;
//	}
//}
////代码优化3 **** 针对：my_strcpy(arr1, NULL)
//void my_strcpy(char* dest, char* src)	//模拟实现库函数：strcpy
//{
//	if (dest != NULL && src != NULL)//针对传入NULL
//	{
//		while (*dest++ = *src++)
//		{
//			;
//		}
//	}
//}
////代码优化4 **** assert()//断言********(发现问题可以将问题抛出来)
//#include <assert.h>
//void my_strcpy(char* dest, char* src)	//模拟实现库函数：strcpy
//{
//	assert(dest != NULL);//断言
//	assert(src != NULL);
//	while (*dest++ = *src++)
//	{
//		;
//	}
//}
////代码优化5 **** const
//#include <assert.h>
//void my_strcpy(char* dest,const char* src)	//模拟实现库函数：strcpy
//{
//	assert(dest != NULL);//断言
//	assert(src != NULL);
//	//while (*src++ = *dest++)//错误
//	while(*dest++ = *src++)
//	{
//		;
//	}
//}
//////代码优化5 **** 函数返回值char*;
//#include <assert.h>
//char* my_strcpy(char* dest,const char* src)	//模拟实现库函数：strcpy
//{
//	char* ret = dest;	//目的地起始地址
//	assert(dest != NULL);//断言
//	assert(src != NULL);
//	//while (*src++ = *dest++)//错误
//	while(*dest++ = *src++)	//把src指向的字符串拷贝到dest指向的空间中，包含'\0'字符
//	{
//		;
//	}
//	return ret;	//返回目的地起始地址
//}
//int main()
//{
//	//strcpy字符串拷贝
//	char arr1[] = "###########";//###########\0
//	char arr2[] = "bit";		//bit\0
//	//strcpy(arr1, arr2);//将arr2里面的b i t \0 拷贝到arr1里面
//	my_strcpy(arr1, arr2);
//	//my_strcpy(arr1, NULL);//****不能传空指针
//	printf("%s\n", arr1);
//	printf("%s\n", my_strcpy(arr1,arr2));	//链式反应
//	return 0;
//}

////理解const修饰指针
//int main()
//{
//	//int num = 10;
//	//const int num = 10;//加上const也会被改（非法）
//	const int num = 10;
//	//const int* p = &num;//const修饰指针：放在*左边时，修饰的是*p：不能通过p来修改*p（num）
//	//*p = 20;//错误
//	// 
//	//int* const p = &num;//const修饰指针：放在*右边时，修饰的是指针变量 p本身：p不能被改变
//	//p = &num;//错误
//	// 
//	//const int* const p = &num;
//	//*p = 20;	//错误
//	//p = &num; //错误
//	printf("num = %d\n", num);
//	return 0;
//}

#include <assert.h>
int my_strlen(const char* str)
{
	int count = 0;
	assert(str != NULL);	//保证指针有效性
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
int main()
{
	char arr[] = "abcdef";
	int len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}

//*************************编程常见的错误******************************//
//1.编译型错误
//直接看错误提示信息（双击），解决问题。或者凭借经验就可以搞定。相对来说简单。
//2.链接型错误
//看错误提示信息，主要在代码中找到错误信息中的标识符，然后定位问题所在。一般是标识符名不
//存在或者拼写错误。
//3.运行时错误
//借助调试，逐步定位问题。最难搞。