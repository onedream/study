#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#define NEW if (toupper(getchar()) == 'Y')
#define EMP while ((str = getchar()) != '\n') //用于清空输入流
static int x = 0; //用来标记是否初次进入菜单
char str;
void input();
void save();
void read();
void output();
struct stu
{
	char name[15];
	int age;
	char sex;
	char num[20];
	char birth[8];
	char addr[20];
	char tel[11];
	char email[20];
}inform[150];
//void insert()
//{
//	int n;
//	printf("请输入需要插入学生的个数：");
//	scanf("%d", &n);
//
//}

void snum()
{
	printf("this is 1\n");
	return;
}
void sage()
{
	printf("this is 2\n");
	return;
}

void sbirth()
{
	printf("this is 3\n");
	return;
}
void stel()
{
	printf("this is 4\n");
	return;
}
//char* cherk()//检查输入信息是否有误
//{
//
//}

int sort()
{
	char n = 5, flag = 2, sum = 0, x;//
	char str;



	while (flag > 0) {
		printf("请输入排序模式(数字)：\n");
		printf("1.学号\t2.年龄\t3.出生年月\t4.电话\n");
		scanf("%c", &n);
		EMP;
		if (n == '1' || n == '2' || n == '3' || n == '4') {
			if (n == '1') snum();
			else if (n == '2') sage();
			else if (n == '3') sbirth();
			else stel();
			flag = 0;
			printf("排序成功!\n");
		}
		else { //这里是排序失败
			flag--;
			if (flag == 1)
				printf("您的输入有误,请等待重试！(%d/2)\n", flag);
			else { printf("两次输入有误,请等待返回菜单！(%d/2)\n", flag); flag--; }
			Sleep(1500);


		}
	}
	if (flag == 0)
	{
		printf("是否查看排序后结果！(Y/N)\n");
		if (toupper(getchar()) == 'Y') return 1;
	}

	return 0;
}

int main()
{
	sort();
	return 0;
}