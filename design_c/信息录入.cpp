#define _CRT_SECURE_NO_WARNINGS
// #include<stdio.h>
// #include<string.h>
// #include<conio.h>
// #include<windows.h>
// #include<stdlib.h>
// #define NEW if (toupper(getchar()) == 'Y')
// #define EMP while ((str = getchar()) != '\n') //�������������
// static int x = 0; //��������Ƿ���ν���˵�
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
	if ((fp = fopen("ѧ����Ϣ��.txt", "w")) == NULL) //
	{
		printf("���ܴ��ļ�\n");
		return;
	}
	for (i = 0; i <= n; i++)
	{
		if (fwrite(&inform[i], sizeof(struct stu), 1, fp) != 1) //
		{
			printf("��Ϣ¼���������������\n");
			i--;
		}
	}
	fclose(fp);
}
void read()
{
	FILE *fp;
	int i;
	fp = fopen("ѧ����Ϣ��.txt", "r");
	if (fp == NULL) //
	{
		printf("���ļ��쳣��\n");
		return;
	}
	fread(&inform[0], sizeof(struct stu), 1, fp);
	printf("ѧ����Ϣ(%d/100):\n����\t����\t�Ա�\tѧ��\t��������\t��ַ\t��ϵ��ʽ\temail\n", inform[0].age);
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
	printf("Ҫ������ٸ�ѧ����Ϣ\n");
	scanf("%d", &n);
	printf("������Щѧ������Ϣ\n");
	for (i = 1; i <= n; i++)
	{
		printf("����%d��ѧ����Ϣ\n����\t����\t�Ա�\tѧ��\t��������\t��ַ\t��ϵ��ʽ\temail\n", i);
		scanf("%s\t%d\t%c\t%s\t%s\t%s\t%s\t%s", inform[i].name, &inform[i].age, &inform[i].sex,
			  inform[i].num, inform[i].birth, inform[i].addr, inform[i].tel, inform[i].email);
	}
	inform[0].age = n;
}
void read()
{
	FILE *fp;
	int i;
	fp = fopen("ѧ����Ϣ��.txt", "r");
	if (fp == NULL) //
	{
		printf("���ļ��쳣��\n");
		return;
	}
	fread(&inform[0], sizeof(struct stu), 1, fp);
	printf("ѧ����Ϣ(%d/100):\n����\t����\t�Ա�\tѧ�š�t��������\t��ַ\t��ϵ��ʽ\temail\n", inform[0].age);
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