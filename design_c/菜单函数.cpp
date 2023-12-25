#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#define NEW if (toupper(getchar()) == 'Y')
#define EMP while ((str = getchar()) != '\n') // 用于清空输入流
static int x = 0;							  // 用来标记是否初次进入菜单
char str;
void input();
void save();
void read();
void output();
typedef struct
{
	char name[15];
	int age;
	char sex;
	char num[20];
	char birth[8];
	char addr[20];
	char tel[11];
	char email[20];
} stu;
stu inform[150];
void menu() /*菜单界面*/
{
	char num = 0;
	int s; /*用于记录输入错误次数*/
	while (1)
	{
		s = 0;
		if (x != 0)
		{
			printf("即将返回菜单，是否需要进行清屏操作(Y/N)\n");
			NEW
				system("cls");
			EMP;
		}
		if (x == 0)
		{ /*初次进入显示欢迎界面*/
			printf(" \n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("\t\t\t\t\tWelcome to this program!  o(〃＾▽＾〃)o");
			Sleep(2500);
			system("cls");
			x++;
			printf("\t\t\t   *若直接输入窗口无果，请先点击窗口后再进行输入操作*\n\n");
		}

		printf(" \t\t\t _________________________________________________________\n");
		printf(" \t\t\t|                    学生信息管理系统                     |\n ");
		printf(" \t\t\t|---------------------------------------------------------|\n");
		printf(" \t\t\t|----------------------系统功能菜单-----------------------|\n");
		printf(" \t\t\t|---------------------------------------------------------|\n");
		printf(" \t\t\t|---------------------------------------------------------|\n");
		printf(" \t\t\t|* 1.录入学生信息           |* 2.查看学生信息             | \n");
		printf(" \t\t\t|---------------------------------------------------------|\n");
		printf(" \t\t\t|* 3.查找学生信息           |* 4.统计人数                 | \n");
		printf(" \t\t\t|---------------------------------------------------------|\n");
		printf(" \t\t\t|* 5.修改学生信息           |* 6.删除学生信息             |\n");
		printf(" \t\t\t|---------------------------------------------------------|\n");
		printf(" \t\t\t|* 7.插入学生信息           |* 8.排序                     |\n");
		printf(" \t\t\t|---------------------------------------------------------|\n");
		printf(" \t\t\t|                      * 9.退出系统                       | \n");
		printf(" \t\t\t|---------------------------------------------------------|\n");
		printf(" \t\t\t|_________________________________________________________|\n");

	w:
		if (s == 4)
		{
			system("cls");
			printf(" \n\n\n\n\n\n\n\n\n\n\n\n");
			printf("\t\t\t\t\t\t操作异常！程序即将结束\n");
			Sleep(1500);
			system("cls");
			exit(1);
		}
		printf("请选择菜单编号:");
		scanf("%c", &num);
		EMP;

		switch (num)
		{
		case 49: /*input(); save(); break;*/
		case 50: /*read(); output();  break;*/
		case 51: // read();sear(); break;
		case 52: // read();count(); break;
		case 53: // read();modify();save(); break;
		case 54: // read();dele();save(); break;
		case 55: // read();insert();save(); break;
		case 56: // read();sort();save();break;
		case 57:
			printf("是否确定退出程序,退出后将清空界面操作记录(Y/N)\n");
			NEW
			{
				system("cls");
				printf(" \n\n\n\n\n\n\n\n\n\n\n\n");
				printf("\t\t\t\t\t\t即将退出程序,再见!(╥﹏╥)\n");
				Sleep(3000);
				system("cls");
				exit(0);
			}
			EMP;
			break;
		default:
			printf("请在1-9之间选择!\n");
			s++;
			goto w;
		}
	}
}

int main()
{
	menu();
	return 0;
}