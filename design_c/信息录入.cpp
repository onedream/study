#define _CRT_SECURE_NO_WARNINGS
// #include<stdio.h>
// #include<string.h>
// #include<conio.h>
// #include<windows.h>
// #include<stdlib.h>
// #define NEW if (toupper(getchar()) == 'Y')
// #define EMP while ((str = getchar()) != '\n') //用于清空输入流
// static int x = 0; //用来标记是否初次进入菜单
// char str;
// int n;
// void input();
// void save();
// void read();
// void output();
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
int n;
char str;
void input();
void save();
void read();
void output();
struct stu
{
	char name[20];
	int age;
	char sex;
	char num[20];
	char birth[15];
	char addr[35];
	char tel[20];
	char email[30];
} inform[150];
void save()
{

	FILE *fp;
	int i;
	if ((fp = fopen("学生信息表.txt", "w")) == NULL) //
	{
		printf("不能打开文件\n");
		return;
	}
	for (i = 0; i <= n; i++)
	{
		if (fwrite(&inform[i], sizeof(struct stu), 1, fp) != 1) //
		{
			printf("信息录入错误，请重新输入\n");
			i--;
		}
	}
	fclose(fp);
}
void read()
{
	FILE *fp;
	int i;
	fp = fopen("学生信息表.txt", "r");
	if (fp == NULL) //
	{
		printf("打开文件异常！\n");
		return;
	}
	fread(&inform[0], sizeof(struct stu), 1, fp);
	printf("学生信息(%d/100):\n姓名\t年龄\t性别\t学号\t出生日期\t地址\t联系方式\temail\n", inform[0].age);
	for (i = 1; i <= inform[0].age; i++)
	{

		fread(&inform[i], sizeof(struct stu), 1, fp); //
		printf("%s\t%d\t%c\t%s\t%s\t%s\t%s\t%s\n", inform[i].name, inform[i].age, inform[i].sex,
			   inform[i].num, inform[i].birth, inform[i].addr, inform[i].tel, inform[i].email);
	}
	fclose(fp);
}
void input()
{
	int i;
	printf("要输入多少个学生信息\n");
	scanf("%d", &n);
	printf("输入这些学生的信息\n");
	for (i = 1; i <= n; i++)
	{
		printf("输入%d号学生信息\n姓名\t年龄\t性别\t学号\t出生日期\t地址\t联系方式\temail\n", i);
		scanf("%s\t%d\t%c\t%s\t%s\t%s\t%s\t%s", inform[i].name, &inform[i].age, &inform[i].sex,
			  inform[i].num, inform[i].birth, inform[i].addr, inform[i].tel, inform[i].email);
	}
	inform[0].age = n;
}
void read()
{
	FILE *fp;
	int i;
	fp = fopen("学生信息表.txt", "r");
	if (fp == NULL) //
	{
		printf("打开文件异常！\n");
		return;
	}
	fread(&inform[0], sizeof(struct stu), 1, fp);
	printf("学生信息(%d/100):\n姓名\t年龄\t性别\t学号、t出生日期\t地址\t联系方式\temail\n", inform[0].age);
	for (i = 1; i <= inform[0].age; i++)
	{

		fread(&inform[i], sizeof(struct stu), 1, fp); //
		printf("%s\t%d\t%c\t%s\t%s\t%s\t%s\t%s\n", inform[i].name, inform[i].age, inform[i].sex,
			inform[i].num, inform[i].birth, inform[i].addr, inform[i].tel, inform[i].email);
	}
	fclose(fp);
}
int main()
{
	input();
	save();
	read();
	return 0;
}