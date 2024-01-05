#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#define NEW if (toupper(getchar()) == 'Y')
#define EMP while ((str = getchar()) != '\n') 
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
void output (){
    for(int i=0;i</*人数*/;i++){
        printf("%s\t%d\t%c\t%s\t%s\t%s\t%s\t%s\n",inform[i].name, inform[i].age, inform[i].sex,
			inform[i].num, inform[i].birth, inform[i].addr, inform[i].tel, inform[i].email);
    }
}