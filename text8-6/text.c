#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//****************************************************//
//���д���ã����ڵ��ԣ��Ĵ���
//1. ������������
//2. bug����			
//3. Ч�ʸ�			
//4. �ɶ��Ը�			
//5. ��ά���Ը�			
//6. ע������			
//7. �ĵ���ȫ	
//****************************************************//	
//������coding���ɣ�
//1. ʹ��assert
//2. ����ʹ��const
//3. �������õı�����
//4. ��ӱ�Ҫ��ע��
//5. ������������
//****************************************************//
//void my_strcpy(char* dest, char* src)	//ģ��ʵ�ֿ⺯����strcpy
//{
//	while (*src != '\0')
//	{
//		*dest = *src;
//		src++;
//		dest++;
//	}
//	*dest = *src;
//}
////�����Ż�1
//void my_strcpy(char* dest, char* src)	//ģ��ʵ�ֿ⺯����strcpy
//{
//	while (*src != '\0')
//	{
//		*dest++ = *src++;
//	}
//	*dest = *src;
//}
////�����Ż�2
//void my_strcpy(char* dest, char* src)	//ģ��ʵ�ֿ⺯����strcpy
//{
//	while (*dest++ = *src++)
//	{
//		;
//	}
//}
////�����Ż�3 **** ��ԣ�my_strcpy(arr1, NULL)
//void my_strcpy(char* dest, char* src)	//ģ��ʵ�ֿ⺯����strcpy
//{
//	if (dest != NULL && src != NULL)//��Դ���NULL
//	{
//		while (*dest++ = *src++)
//		{
//			;
//		}
//	}
//}
////�����Ż�4 **** assert()//����********(����������Խ������׳���)
//#include <assert.h>
//void my_strcpy(char* dest, char* src)	//ģ��ʵ�ֿ⺯����strcpy
//{
//	assert(dest != NULL);//����
//	assert(src != NULL);
//	while (*dest++ = *src++)
//	{
//		;
//	}
//}
////�����Ż�5 **** const
//#include <assert.h>
//void my_strcpy(char* dest,const char* src)	//ģ��ʵ�ֿ⺯����strcpy
//{
//	assert(dest != NULL);//����
//	assert(src != NULL);
//	//while (*src++ = *dest++)//����
//	while(*dest++ = *src++)
//	{
//		;
//	}
//}
//////�����Ż�5 **** ��������ֵchar*;
//#include <assert.h>
//char* my_strcpy(char* dest,const char* src)	//ģ��ʵ�ֿ⺯����strcpy
//{
//	char* ret = dest;	//Ŀ�ĵ���ʼ��ַ
//	assert(dest != NULL);//����
//	assert(src != NULL);
//	//while (*src++ = *dest++)//����
//	while(*dest++ = *src++)	//��srcָ����ַ���������destָ��Ŀռ��У�����'\0'�ַ�
//	{
//		;
//	}
//	return ret;	//����Ŀ�ĵ���ʼ��ַ
//}
//int main()
//{
//	//strcpy�ַ�������
//	char arr1[] = "###########";//###########\0
//	char arr2[] = "bit";		//bit\0
//	//strcpy(arr1, arr2);//��arr2�����b i t \0 ������arr1����
//	my_strcpy(arr1, arr2);
//	//my_strcpy(arr1, NULL);//****���ܴ���ָ��
//	printf("%s\n", arr1);
//	printf("%s\n", my_strcpy(arr1,arr2));	//��ʽ��Ӧ
//	return 0;
//}

////���const����ָ��
//int main()
//{
//	//int num = 10;
//	//const int num = 10;//����constҲ�ᱻ�ģ��Ƿ���
//	const int num = 10;
//	//const int* p = &num;//const����ָ�룺����*���ʱ�����ε���*p������ͨ��p���޸�*p��num��
//	//*p = 20;//����
//	// 
//	//int* const p = &num;//const����ָ�룺����*�ұ�ʱ�����ε���ָ����� p����p���ܱ��ı�
//	//p = &num;//����
//	// 
//	//const int* const p = &num;
//	//*p = 20;	//����
//	//p = &num; //����
//	printf("num = %d\n", num);
//	return 0;
//}

#include <assert.h>
int my_strlen(const char* str)
{
	int count = 0;
	assert(str != NULL);	//��ָ֤����Ч��
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

//*************************��̳����Ĵ���******************************//
//1.�����ʹ���
//ֱ�ӿ�������ʾ��Ϣ��˫������������⡣����ƾ�辭��Ϳ��Ը㶨�������˵�򵥡�
//2.�����ʹ���
//��������ʾ��Ϣ����Ҫ�ڴ������ҵ�������Ϣ�еı�ʶ����Ȼ��λ�������ڡ�һ���Ǳ�ʶ������
//���ڻ���ƴд����
//3.����ʱ����
//�������ԣ��𲽶�λ���⡣���Ѹ㡣