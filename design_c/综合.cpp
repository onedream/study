#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#define NEW if (toupper(getchar()) == 'Y')
#define EMP while ((str = getchar()) != '\n') //用于清空输入流
static int x = 0; //用来标记是否初次进入菜单
int n;
char str;
void input();
void save();
int read();
void dele();
void insert();
void count();
void sort();
void output();
void modify();
int msert(int n);
void esert(int n);
void sear();
struct stu
{
	char name[15];
	int age;
	char sex;
	char num[20];
	char birth[15];
	char addr[35];
	char tel[20];
	char email[30];
}inform[151];

void menu() /*菜单界面*/
{
	char num = 0;
	int s;/*用于记录输入错误次数*/
	while (1) {
	c:
		s = 0;
		if (x != 0) {

			printf("即将返回菜单，是否需要进行清屏操作(Y/N)\n");
			NEW
				system("cls");
			EMP;
		}
		if (x == 0) {/*初次进入显示欢迎界面*/
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
		if (s == 3) {
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
		if (num != '1'&&num!='9')
			if (!read()) goto c;
		switch (num)
		{
		case 49:input(); save(); break;
		case 50:read(); output();  break;
		case 51:read(); sear(); break;
		case 52:read(); count(); break;
		case 53:read(); modify(); save(); break;
		case 54:read(); dele(); save(); break;
		case 55:read(); insert(); save(); break;
		case 56:read(); sort(); save(); break;
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
		default:printf("请在1-9之间选择!\n");  s++; goto w;
		}
	}
}

void save()
{

	FILE* fp;
	int i;
	if ((fp = fopen("学生信息表.txt", "w")) == NULL)
	{
		printf("不能打开文件\n");
		return;
	}
	for (i = 0; i <= inform[0].age; i++)
	{
		if (fwrite(&inform[i], sizeof(struct stu), 1, fp) != 1)
		{
			printf("信息录入错误，请重新输入\n");
			i--;
		}

	}
	fclose(fp);
}

void input()
{
	int i, n, j = 0, flag = 0;
	char s[20], x;
	printf("要输入多少个学生信息\n");
	scanf("%d", &n);
	printf("输入这些学生的信息(输入过程中需要终止，输入单个字符Y)\n");
	for (i = 1; i <= n; i++)
	{

		printf("输入%d号学生信息\n姓名\t年龄\t性别(M/F)\t学号\t出生日期\t地址\t联系方式\temail\n", i);
		scanf("%s", s);
		if (strlen(s) == 1 && toupper(s[0]) == 'Y') {/*这用于判断该学生姓名是否为y*/
			x = getchar();
			if (x == 9 || x == ' ') strcpy(inform[i].name, s); //这里判断输入的这个y后面的是tab或空格
			if (x == '\n') { flag++; goto w; }//若是换行则表明停止输入
		}
		else strcpy(inform[i].name, s); //非y名字输入
		scanf("%d\t%c\t%s\t%s\t%s\t%s\t%s", &inform[i].age, &inform[i].sex,
			inform[i].num, inform[i].birth, inform[i].addr, inform[i].tel, inform[i].email);
	}
w:
	inform[0].age = i - 1;
	if (flag == 1) return;
	EMP;
	return;
}
/***************************************************/
int read()
{
	FILE* fp;
	int i;
	fp = fopen("学生信息表.txt", "r");
	if (fp == NULL) //
	{
		printf("打开文件异常！\n");
		return 0;
	}
	fread(&inform[0], sizeof(struct stu), 1, fp);
	if (inform[0].age == 0) {
		printf("请先将数据录入到文件中！");
		return 0;
	}
	for (i = 1; i <= inform[0].age; i++)
	{

		fread(&inform[i], sizeof(struct stu), 1, fp); //
	}
	fclose(fp);
	return 1;
}

void output()
{
	int i;
	printf("学生信息(%d/100):\n姓名\t年龄\t性别\t学号\t出生日期\t地址\t联系方式\temail\n", inform[0].age);
	for (i = 1; i <= inform[0].age; i++)
	{
		printf("%s\t%d\t%c\t%s\t%s\t%s\t%s\t%s\n", inform[i].name, inform[i].age, inform[i].sex,
			inform[i].num, inform[i].birth, inform[i].addr, inform[i].tel, inform[i].email);
	}

}

/***************************************************/

void sear1()
{
	char xh[30], s;
	int ji;
	printf("请输入想要查找的学生学号：\n");
	scanf("%s", xh);
	for (ji = 1; ji <= inform[0].age; ji++) {
		if (strcmp(inform[ji].num, xh) == 0)
			break;
	}
	if (ji == inform[0].age + 1) printf("未找到指定的学生!");
	else {
		printf("已查找到该学生，是否需要输出该学生的信息：(Y/N)\n");
		EMP;
		scanf("%c", &s);
		printf("%c", s);
		EMP;
		if (toupper(s) == 'Y') printf("该学生的信息为：\n\n姓名：%-5s\n年龄：%-5d\n性别：%-5c\n学号：%-5s\n生日：%-5s\naddr：%-5s\n电话：%-5s\nemail：%-5s\n", inform[ji].name, inform[ji].age, inform[ji].sex, inform[ji].num, inform[ji].birth, inform[ji].addr, inform[ji].tel, inform[ji].email);
	}
}

void sear2()
{
	int old, sum = 0, i, j = 0;
	struct stu s[50];
	printf("请输入你要查询学生的年龄：\n");
	scanf("%d", &old);
	EMP;
	for (i = 1; i <= inform[0].age; i++)
	{
		if (inform[i].age == old) {
			sum++;
			s[j] = inform[i];
			j++;
		}
	}
	printf("通过年龄查询到共有%d个学生\n", sum);
	printf("是否需要输出该年龄的全部学生信息:(Y/N)\n");
	NEW{
		EMP;
		printf("该年龄的全部学生信息如下：\n");
	printf("姓名\t年龄\t性别\t学号\t生日\taddr\t电话\temail\n");
		for (i = 0; i < j; i++) {
			printf("%s\t%d\t%c\t%s\t%s\t%s\t%s\t%s\n", s[i].name, s[i].age, s[i].sex, s[i].num, s[i].birth, s[i].addr, s[i].tel, s[i].email);
}
	}
}

void sear()
{
	char look;
	int flag = 2;
	printf("请选择您的查询方式\n");
	printf("A:通过学号查询\tB:通过年龄查询\n");

	while (1)
	{
		scanf("%c", &look);
		EMP;
		look = toupper(look);
		if (look == 65 || look == 66)
			break;
		if (flag == 0) { printf("操作异常，即将返回菜单!\n"); Sleep(1500); return; }
		else { printf("输入错误 请重新输入(%d/3):\n", flag); flag--; }
	}
	switch (look) {
	case 65: 	sear1(); break;
	case 66:    sear2(); break;
	}
}

void sum3(int oldd) //按具体年龄进行统计 
{
	int oo, summ = 0;
	for (oo = 1; oo <= inform[0].age; oo++)//inform[0].age为录入信息的学生数量 
	{
		if (inform[oo].age == oldd)
			summ++;
	}
	printf("该年龄的学生累计：%d人\n", summ);
	summ = 0;
}
void sum2(int min, int max) { //按年龄范围进行统计 
	int x, summ = 0;
	for (x = 1; x <= inform[0].age; x++)
	{
		if (inform[x].age >= min && inform[x].age <= max) summ++;

	}
	printf("该年龄段的学生累计:%d人\n", summ);
}
void sum1(char xd)//按性别统计 
{
	int pp, summ = 0;
	printf("%c", xd);
	for (pp = 1; pp <= inform[0].age; pp++)
	{
		if (toupper(inform[pp].sex) == xd)
		{
			summ++;
		}
	}
	if (xd == 'M')
		printf("男生总计：%d人\n", summ);
	else printf("女生总计：%d人\n", summ);
	summ = 0;
}

void count()
{
	int eg = 0, oldd, min, max, flag = 3;
	printf("请选择统计模式:\n");
	printf("M:男生人数\t F:女生人数\tG:某一年龄的人数\tA:某一年龄段的人数\n");
	char og;
	while (1)
	{
		scanf("%c", &og);
		EMP;
		if (og == 'm' || og == 'M')
		{
			sum1('M');
			break;
		}
		else if (og == 'f' || og == 'F')
		{
			sum1('F');
			break;
		}
		else if (og == 'g' || og == 'G')
		{
			printf("请输入您要统计的某一年龄人数的年龄:\n");

			scanf("%d", &oldd);
			EMP;
			sum3(oldd);
			break;
		}
		else if (og == 'A' || og == 'a') {
			do {

				if (flag == 3) { printf("请输入年龄范围(前小后大,空格隔开)：\n"); flag--; }
				else if (min >= max || min > 104 || max > 104 || min <= 0) { printf("您的输入有误,请重新输入!\n"); flag--; }
				else break;
				scanf("%d%d", &min, &max);
				EMP;
			} while (flag);
			if (flag) sum2(min, max);
			break;
		}
		else
		{
			eg++;
			if (eg == 3) {
				printf("输入三次有误,即将返回菜单\n");
				Sleep(1500);
				break;
			}
			printf("输入错误请重新输入（若连续输入错误三次将自动回到菜单界面(%d/3)!）\n", 3 - eg);

		}
	}

}

/***************************************************/

void modify()
{
	int i, x, age1, num_idx = -1;
	char name2[20], sex1, num1[20], birth1[15], addr1[35], tel1[20], email1[20];
	printf("请输入你想修改的学生学号:");
	scanf("%s", num1);
	for (i = 1; i <= inform[0].age; i++)
	{
		if (strcmp(inform[i].num, num1) == 0)
		{
			num_idx = i;
			break;
		}
	}
	if (num_idx == -1)
	{
		printf("查无此人");
		return;//false
	}
	EMP;
	printf("是否需要修改学生的全部信息(Y/N)\n");
	NEW
	{
	EMP;
	printf("请输入新的学生信息；\n姓名\t年龄\t性别\t学号\t出生年月\t地址\t电话\temail\t\n");
	scanf("%s\t%d\t%c\t%s\t%s\t%s\t%s\t%s", inform[num_idx].name, &inform[num_idx].age, &inform[num_idx].sex, inform[num_idx].num, inform[num_idx].birth, inform[num_idx].addr, inform[num_idx].tel, inform[num_idx].email);
	}
	else
	{
		printf("\n1.修改姓名\t2.修改年龄\t3.修改性别\t4.修改学号\n5.修改出生年月\t6.修改地址\t7.修改电话\t8.修改email\t9.退出本菜单\n请输入子菜单编号：\n");
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
			scanf("%d", &age1);
			inform[num_idx].age = age1;
			break;
		case 3:
			printf("请输入新的性别:\n");
			scanf("%c", &sex1);
			inform[num_idx].sex = sex1;
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
			EMP;
			return;//false
		default:
			printf("请在1-9之间选择\n");
		}

	}
	EMP;
	printf("修改完毕！");
	return;//true
}
void dele()
{
	int i, j, k = 0;
	char num2[20];
	printf("请输入要删除学生的学号\n");
	scanf("%s", num2);
	EMP;
	for (i = 1; i <= inform[0].age; i++)
	{
		if (strcmp(inform[i].num, num2) == 0)
		{
			k = 1;
			for (j = i; j <= inform[0].age - 1; j++)
				inform[j] = inform[j + 1];
			break;
		}
	}
	if (!k)
	{
		printf("查无此人\n");
	}
	else
	{
		inform[0].age--;
		EMP;
		printf("修改成功,是否查看删除后结果！(Y/N)\n");

		NEW{ EMP; output(); }
	}
}
/***************************************************/
int msert(int n)
{
	int i, j;
	char s[20], sel, flag = 3;
	printf("请输入需要插入位置附近人的学号：\n");
	while (flag) {
		if (flag != 3)printf("请重新输入(%d/3):\n", flag);
		scanf("%s", s);
		getchar();

		for (i = 1; i <= inform[0].age; i++) {
			if (strcmp(inform[i].num, s) == 0)
				break;
		}
		if (i == inform[0].age + 1) {
			printf("您输入的学号有误,该学生不存在!\n"); flag--;
			if (!flag) { printf("操作异常，即将返回菜单!\n"); Sleep(1500); return 0; }
			continue;
		}
		break;
	}
	flag = 3;
	printf("请输入是需要到插入到该学号:\nA.前面\tB.后面\n");
	while (flag) {
		if (flag != 3)printf("请重新输入(%d/3):\n", flag);
		scanf("%c", &sel);
		EMP;
		sel = toupper(sel);
		if (sel != 'A' && sel != 'B') {
			printf("您输入的选项有误！\n"); flag--;
			if (!flag) { printf("操作异常，即将返回菜单!\n"); Sleep(1500); return 0; }
			continue;
		}

		break;
	}
	//i为该学生
	if (sel == 'A') {
		if (i == inform[0].age) {       //若该学号为最后一个人
			inform[i + n] = inform[i];
		}
		else {
		a:
			for (j = inform[0].age; j >= i; j--) {
				inform[j + n] = inform[j];
			}
		}
		printf("请输入需要插入学生信息：\n");
		printf("\t	姓名\t年龄\t性别(M/F)\t学号\t出生日期\t地址\t联系方式\temail\n");
		for (j = 0; j < n; j++) {
			printf("第%d位同学:\t", j + 1);
			scanf("%s\t%d\t%c\t%s\t%s\t%s\t%s\t%s", inform[i + j].name, &inform[i + j].age, &inform[i + j].sex, inform[i + j].num, inform[i + j].birth, inform[i + j].addr, inform[i + j].tel, inform[i + j].email);
		}
		inform[0].age += j;
		return 1;
	}
	else {     /*在后面插入的情况*/
		if (i == inform[0].age) {   //若该学号为最后一个人
			esert(n); return 1;
		}
		else { i++; goto a; }
	}

}

void esert(int n)
{
	int i;
	printf("请输入需要插入学生信息：\n");
	printf("\t	姓名\t年龄\t性别(M/F)\t学号\t出生日期\t地址\t联系方式\temail\n");
	for (i = 1; i <= n; i++) {
		printf("第%d位同学:\t", i);
		scanf("%s\t%d\t%c\t%s\t%s\t%s\t%s\t%s", inform[inform[0].age + i].name, &inform[inform[0].age + i].age, &inform[inform[0].age + i].sex, inform[inform[0].age + i].num, inform[inform[0].age + i].birth, inform[inform[0].age + i].addr, inform[inform[0].age + i].tel, inform[inform[0].age + i].email);

	}
	inform[0].age += n;
	return;
}

void insert()
{
	int n, flag = 2, sum = 2, x = 2;//
	char str1;
	printf("请输入需要插入的人数：(%d/100)\n", inform[0].age);
	while (x > 0) {
		if (x != 2)
			printf("请再次输入：\n");
		scanf("%d", &n);

		if (n > (100 - inform[0].age)) {
			x--;
			if (x)
			{
				printf("插入人数多于内存容纳量,请等待重新输入!(%d/2)\n", x);
				Sleep(1500);
			}
		}
		else x = -1;
		if (x == 0) {
			printf("操作异常即将返回菜单！\n");
			EMP;
			Sleep(1500);
			return;
		}
	}
	EMP;
	while (flag > 0) {
		if (flag == 2)
			printf("请输入插入的模式(数字):\n1.中间插入\t2.最后插入\t\n");
		else printf("请再次输入:\n");
		scanf("%c", &str1);

		if (str1 == '1' || str1 == '2') {
			if (str1 == '1') { if (!msert(n)) return; }
			else { esert(n); }
			flag = 0;
			printf("插入成功!\n");
		}
		else {
			flag--;
			if (flag == 1)
				printf("您的输入有误,请等待重试！(%d/2)\n", flag);
			else { printf("两次输入有误,请等待返回菜单！(%d/2)\n", flag); EMP; flag--; }
			Sleep(1500);


		}
	}
	if (flag == 0)
	{
		EMP;
		printf("是否查看插入后结果！(Y/N)\n");

		NEW{ EMP; output(); }

	}

	return;
}

void snum(char str2)
{

	int i, j, flag = 0;
	struct stu temp;
	for (i = 1; i <= inform[0].age - 1; i++) {
		for (j = 1; j <= inform[0].age - i; j++) {
			flag = 0;
			if ((str2 == 'A' && (strcmp(inform[j].num, inform[j + 1].num) > 0)) || (str2 == 'D' && strcmp(inform[j].num, inform[j + 1].num) < 0)) {
				temp = inform[j];
				inform[j] = inform[j + 1];
				inform[j + 1] = temp;
			}

		}
	}
	return;
}
void sage(char str2)
{
	int i, j, flag = 0;
	struct stu temp;
	for (i = 1; i <= inform[0].age - 1; i++) {
		for (j = 1; j <= inform[0].age - i; j++) {
			flag = 0;
			if ((str2 == 'A' && (inform[j].age > inform[j + 1].age)) || (str2 == 'D' && (inform[j].age < inform[j + 1].age))) {
				temp = inform[j];
				inform[j] = inform[j + 1];
				inform[j + 1] = temp;
			}

		}
	}
	return;
}

void sbirth(char str2)
{
	int i, j, flag = 0;
	struct stu temp;
	for (i = 1; i <= inform[0].age - 1; i++) {
		for (j = 1; j <= inform[0].age - i; j++) {
			flag = 0;
			if ((str2 == 'A' && (strcmp(inform[j].birth, inform[j + 1].birth) > 0)) || (str2 == 'D' && strcmp(inform[j].birth, inform[j + 1].birth) < 0)) {
				temp = inform[j];
				inform[j] = inform[j + 1];
				inform[j + 1] = temp;
			}

		}
	}
	return;
}
void stel(char str2)
{
	int i, j, flag = 0;
	struct stu temp;
	for (i = 1; i <= inform[0].age - 1; i++) {
		for (j = 1; j <= inform[0].age - i; j++) {
			flag = 0;
			if ((str2 == 'A' && (strcmp(inform[j].tel, inform[j + 1].tel) > 0)) || (str2 == 'D' && strcmp(inform[j].tel, inform[j + 1].tel) < 0)) {
				temp = inform[j];
				inform[j] = inform[j + 1];
				inform[j + 1] = temp;
			}

		}
	}
	return;
}

void sort()
{
	char n = 5, flag = 2, sum = 0, x;//
	char str2;
	while (flag > 0) {
		if (flag == 2)
			printf("请输入排序模式(数字)：\n1.学号\t2.年龄\t3.出生年月\t4.电话\n");
		else printf("请再次输入：\n");
		scanf("%c", &n);
		EMP;
		if (n == '1' || n == '2' || n == '3' || n == '4') {
			printf("排序模式是否使用默认升序(Y/N)\n");
			NEW str2 = 'A';
		else str2 = 'D';
		EMP;
		if (n == '1') snum(str2);
		else if (n == '2') sage(str2);
		else if (n == '3') sbirth(str2);
		else stel(str2);
		flag = 0;
		printf("排序成功!\n");
		}
		else {
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
		NEW{ EMP; output(); return; }
	}

	return;
}
int main()
{

	system("color F1");
	menu();
	return 0;
}