#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#define NEW if (toupper(getchar()) == 'Y')
#define EMP while ((str = getchar()) != '\n') // �������������
static int x = 0;							  // ��������Ƿ���ν���˵�
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
void menu() /*�˵�����*/
{
	char num = 0;
	int s; /*���ڼ�¼����������*/
	while (1)
	{
		s = 0;
		if (x != 0)
		{
			printf("�������ز˵����Ƿ���Ҫ������������(Y/N)\n");
			NEW
				system("cls");
			EMP;
		}
		if (x == 0)
		{ /*���ν�����ʾ��ӭ����*/
			printf(" \n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("\t\t\t\t\tWelcome to this program!  o(���ި��ޡ�)o");
			Sleep(2500);
			system("cls");
			x++;
			printf("\t\t\t   *��ֱ�����봰���޹������ȵ�����ں��ٽ����������*\n\n");
		}

		printf(" \t\t\t _________________________________________________________\n");
		printf(" \t\t\t|                    ѧ����Ϣ����ϵͳ                     |\n ");
		printf(" \t\t\t|---------------------------------------------------------|\n");
		printf(" \t\t\t|----------------------ϵͳ���ܲ˵�-----------------------|\n");
		printf(" \t\t\t|---------------------------------------------------------|\n");
		printf(" \t\t\t|---------------------------------------------------------|\n");
		printf(" \t\t\t|* 1.¼��ѧ����Ϣ           |* 2.�鿴ѧ����Ϣ             | \n");
		printf(" \t\t\t|---------------------------------------------------------|\n");
		printf(" \t\t\t|* 3.����ѧ����Ϣ           |* 4.ͳ������                 | \n");
		printf(" \t\t\t|---------------------------------------------------------|\n");
		printf(" \t\t\t|* 5.�޸�ѧ����Ϣ           |* 6.ɾ��ѧ����Ϣ             |\n");
		printf(" \t\t\t|---------------------------------------------------------|\n");
		printf(" \t\t\t|* 7.����ѧ����Ϣ           |* 8.����                     |\n");
		printf(" \t\t\t|---------------------------------------------------------|\n");
		printf(" \t\t\t|                      * 9.�˳�ϵͳ                       | \n");
		printf(" \t\t\t|---------------------------------------------------------|\n");
		printf(" \t\t\t|_________________________________________________________|\n");

	w:
		if (s == 4)
		{
			system("cls");
			printf(" \n\n\n\n\n\n\n\n\n\n\n\n");
			printf("\t\t\t\t\t\t�����쳣�����򼴽�����\n");
			Sleep(1500);
			system("cls");
			exit(1);
		}
		printf("��ѡ��˵����:");
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
			printf("�Ƿ�ȷ���˳�����,�˳�����ս��������¼(Y/N)\n");
			NEW
			{
				system("cls");
				printf(" \n\n\n\n\n\n\n\n\n\n\n\n");
				printf("\t\t\t\t\t\t�����˳�����,�ټ�!(�i�n�i)\n");
				Sleep(3000);
				system("cls");
				exit(0);
			}
			EMP;
			break;
		default:
			printf("����1-9֮��ѡ��!\n");
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