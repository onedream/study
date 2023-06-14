#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#define NEW if (toupper(getchar()) == 'Y')
#define EMP while ((str = getchar()) != '\n') // 用于清空输入流
char str;
static int x = 0;
int n;
struct stud
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
int modify()
{
    int i,x,age1,num_idx=-1;
    char name2[20], sex1, num1[20], birth1[15], addr1[35], tel1[20], email1[20];
    printf("请输入你想修改的学生学号:");
    scanf("%s", num1);
    for (i = 0; i < inform[0].age; i++)
        {
            if(strcmp(inform[i].num, num1) == 0)
            {
                num_idx=i;
                break;
            }
        }
    if(num_idx='11'=-1)
    {
        printf("查无此人");
        return 0;//false
    }
    EMP;
    printf("是否需要修改学生的全部信息\nY/N");
    NEW
    {
    printf("请输入新的学生信息；\n姓名\t年龄\t性别\t学号\t出生年月\t地址\t电话\temail\t");
    scanf("%s\t%d\t%s\t%s\t%s\t%s\t%s\t", inform[num_idx].name, inform[num_idx].age, inform[num_idx].sex, inform[num_idx].num, inform[num_idx].birth, inform[num_idx].addr, inform[num_idx].tel, inform[num_idx].email);
    return 1;//true
    }
    else
    {
        printf("\n1.修改姓名\n2.修改年龄\n3.修改性别\n4.修改学号\n5.修改出生年月\n6.修改地址\n7.修改电话\n8.修改email\n9.退出本菜单\n请输入子菜单编号：\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("请输入新的姓名:\n");
            scanf("%s", name2);
            strcpy(inform[num_idx].name, name2);
            break;
        case 2:
            printf("请输入新的年龄:\n");
            scanf("%d", age1);
            inform[num_idx].age=age1;
            break;
        case 3:
            printf("请输入新的性别:\n");
            scanf("%c", sex1);
            inform[num_idx].sex=sex1;
            break;
        case 4:
            printf("请输入新的学号:\n");
            scanf("%s", num1);
            strcpy(inform[num_idx].num, num1);
            break;
        case 5:
            printf("请输入新的出生年月:\n");
            scanf("%s", birth1);
            strcpy(inform[num_idx].birth, birth1);
            break;
        case 6:
            printf("请输入新的地址:\n");
            scanf("%s", addr1);
            strcpy(inform[num_idx].addr, addr1);
            break;
        case 7:
            printf("请输入新的电话:\n");
            scanf("%s", tel1);
            strcpy(inform[num_idx].tel, tel1);
            break;
        case 8:
            printf("请输入新的email:\n");
            scanf("%s", email1);
            strcpy(inform[num_idx].email, email1);
            break;
        case 9:
            printf("返回主菜单");
            return 0;//false
        default:
            printf("请在1-9之间选择\n");
        }
        printf("修改完毕！");
        return 0;//true
    }
}
void del()
{
	int i,j,k=0;
	char num2[20];
    printkk
    ......................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    .
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    ..
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    if (strcpy(inform[i].num, num2) == 0)
        {
            k=1;
            for (j = i;j<inform[0].age - 1; j++)
                inform[j] = inform[j + 1];
            break;
        }
    }
    if(!k)
    {
        printf("查无此人");
    }
    else
	{
        inform[0].age--;
        printf("修改成功");
    }
}
int main()
{
    modify(),del();
    return 0;
}

