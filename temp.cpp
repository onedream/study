#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#define NEW if (toupper(getchar()) == 'Y')
#define EMP while ((str = getchar()) != '\n') // �������������
static int x = 0;							  // ��������Ƿ���ν���˵�
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
} inform[151];

void menu() /*�˵�����*/
{
	char num = 0, num1[10];
	int s; /*���ڼ�¼����������*/
	while (1)
	{
	c:
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
		if (s == 3)
		{
			system("cls");
			printf(" \n\n\n\n\n\n\n\n\n\n\n\n");
			printf("\t\t\t\t\t\t�����쳣�����򼴽�����\n");
			Sleep(1500);
			system("cls");
			exit(1);
		}
		printf("��ѡ��˵����:");
		scanf("%s", num1);
		if (strlen(num1) != 1)
			num = '0';
		else
			num = num1[0];
		EMP;
		if (num != '1' && num != '9')
			if (!read())
				goto c;
		switch (num)
		{
		case 49:
			input();
			save();
			break;
		case 50:
			read();
			output();
			break;
		case 51:
			read();
			sear();
			break;
		case 52:
			read();
			count();
			break;
		case 53:
			read();
			modify();
			save();
			break;
		case 54:
			read();
			dele();
			save();
			break;
		case 55:
			read();
			insert();
			save();
			break;
		case 56:
			read();
			sort();
			save();
			break;
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

void save()
{

	FILE *fp;
	int i;
	if ((fp = fopen("ѧ����Ϣ��.txt", "w")) == NULL)
	{
		printf("���ܴ��ļ�\n");
		return;
	}
	for (i = 0; i <= inform[0].age; i++)
	{
		if (fwrite(&inform[i], sizeof(struct stu), 1, fp) != 1)
		{
			printf("��Ϣ¼���������������\n");
			i--;
		}
	}
	fclose(fp);
}

void input()
{
	int i, n, j = 0, flag = 0;
	char s[20], x;
	printf("Ҫ������ٸ�ѧ����Ϣ\n");
	scanf("%d", &n);
	printf("������Щѧ������Ϣ(�����������Ҫ��ֹ�����뵥���ַ�Y)\n");
	for (i = 1; i <= n; i++)
	{

		printf("����%d��ѧ����Ϣ\n����\t����\t�Ա�(M/F) ѧ��\t��������    \t��ַ\t\t��ϵ��ʽ\temail\n", i);
		scanf("%s", s);
		if (strlen(s) == 1 && toupper(s[0]) == 'Y')
		{ /*�������жϸ�ѧ�������Ƿ�Ϊy*/
			x = getchar();
			if (x == 9 || x == ' ')
				strcpy(inform[i].name, s); // �����ж���������y�������tab��ո�
			if (x == '\n')
			{
				flag++;
				goto w;
			} // ���ǻ��������ֹͣ����
		}
		else
			strcpy(inform[i].name, s); // ��y��������
		    scanf("%d\t%c\t%s\t%s\t%s\t%s\t%s", &inform[i].age, &inform[i].sex,
		    inform[i].num, inform[i].birth, inform[i].addr, inform[i].tel, inform[i].email);
	}
w:
	inform[0].age = i - 1;
	if (flag == 1)
	{
		printf("�ɹ�¼��%dλͬѧ����Ϣ\n", inform[0].age);
		return;
	}
	EMP;
	printf("�ɹ�¼��%dλͬѧ����Ϣ\n", inform[0].age);
	return;
}
/***************************************************/
int read()
{
	FILE *fp;
	int i;
	fp = fopen("ѧ����Ϣ��.txt", "r");
	if (fp == NULL) //
	{
		printf("���ļ��쳣��\n");
		return 0;
	}
	fread(&inform[0], sizeof(struct stu), 1, fp);
	if (inform[0].age == 0)
	{
		printf("���Ƚ�����¼�뵽�ļ��У�");
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
	printf("ѧ����Ϣ(%d/100):\n����\t����\t�Ա�\tѧ��\t��������\t��ַ\t��ϵ��ʽ\temail\n", inform[0].age);
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
	printf("��������Ҫ���ҵ�ѧ��ѧ�ţ�\n");
	scanf("%s", xh);
	for (ji = 1; ji <= inform[0].age; ji++)
	{
		if (strcmp(inform[ji].num, xh) == 0)
			break;
	}
	if (ji == inform[0].age + 1)
	{
		printf("δ�ҵ�ָ����ѧ��!");
		EMP;
	}
	else
	{
		printf("�Ѳ��ҵ���ѧ�����Ƿ���Ҫ�����ѧ������Ϣ��(Y/N)\n");
		EMP;
		scanf("%c", &s);
		printf("%c", s);
		EMP;
		if (toupper(s) == 'Y')
			printf("��ѧ������ϢΪ��\n\n������%-5s\n���䣺%-5d\n�Ա�%-5c\nѧ�ţ�%-5s\n���գ�%-5s\naddr��%-5s\n�绰��%-5s\nemail��%-5s\n", inform[ji].name, inform[ji].age, inform[ji].sex, inform[ji].num, inform[ji].birth, inform[ji].addr, inform[ji].tel, inform[ji].email);
	}
}

void sear2()
{
	int old, sum = 0, i, j = 0;
	struct stu s[50];
	printf("��������Ҫ��ѯѧ�������䣺\n");
	scanf("%d", &old);
	EMP;
	for (i = 1; i <= inform[0].age; i++)
	{
		if (inform[i].age == old)
		{
			sum++;
			s[j] = inform[i];
			j++;
		}
	}
	printf("ͨ�������ѯ������%d��ѧ��\n", sum);
	printf("�Ƿ���Ҫ����������ȫ��ѧ����Ϣ:(Y/N)\n");
	NEW
	{
		EMP;
		printf("�������ȫ��ѧ����Ϣ���£�\n");
		printf("����\t����\t�Ա�\tѧ��\t����\taddr\t�绰\temail\n");
		for (i = 0; i < j; i++)
		{
			printf("%s\t%d\t%c\t%s\t%s\t%s\t%s\t%s\n", s[i].name, s[i].age, s[i].sex, s[i].num, s[i].birth, s[i].addr, s[i].tel, s[i].email);
		}
	}
}

void sear()
{
	char look;
	int flag = 2;
	printf("��ѡ�����Ĳ�ѯ��ʽ\n");
	printf("A:ͨ��ѧ�Ų�ѯ\tB:ͨ�������ѯ\n");

	while (1)
	{
		scanf("%c", &look);
		EMP;
		look = toupper(look);
		if (look == 65 || look == 66)
			break;
		if (flag == 0)
		{
			printf("�����쳣���������ز˵�!\n");
			Sleep(1500);
			return;
		}
		else
		{
			printf("������� ����������(%d/3):\n", flag);
			flag--;
		}
	}
	switch (look)
	{
	case 65:
		sear1();
		break;
	case 66:
		sear2();
		break;
	}
}

void sum3(int oldd) // �������������ͳ��
{
	int oo, summ = 0;
	for (oo = 1; oo <= inform[0].age; oo++) // inform[0].ageΪ¼����Ϣ��ѧ������
	{
		if (inform[oo].age == oldd)
			summ++;
	}
	printf("�������ѧ���ۼƣ�%d��\n", summ);
	summ = 0;
}
void sum2(int min, int max)
{ // �����䷶Χ����ͳ��
	int x, summ = 0;
	for (x = 1; x <= inform[0].age; x++)
	{
		if (inform[x].age >= min && inform[x].age <= max)
			summ++;
	}
	printf("������ε�ѧ���ۼ�:%d��\n", summ);
}
void sum1(char xd) // ���Ա�ͳ��
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
		printf("�����ܼƣ�%d��\n", summ);
	else
		printf("Ů���ܼƣ�%d��\n", summ);
	summ = 0;
}

void count()
{
	int eg = 0, oldd, min, max, flag = 3;
	printf("��ѡ��ͳ��ģʽ:\n");
	printf("M:��������\t F:Ů������\tG:ĳһ���������\tA:ĳһ����ε�����\n");
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
			printf("��������Ҫͳ�Ƶ�ĳһ��������������:\n");

			scanf("%d", &oldd);
			EMP;
			sum3(oldd);
			break;
		}
		else if (og == 'A' || og == 'a')
		{
			do
			{

				if (flag == 3)
				{
					printf("���������䷶Χ(ǰС���,�ո����)��\n");
					flag--;
				}
				else if (min >= max || min > 104 || max > 104 || min <= 0)
				{
					printf("������������,����������!\n");
					flag--;
				}
				else
					break;
				scanf("%d%d", &min, &max);
				EMP;
			} while (flag);
			if (flag)
				sum2(min, max);
			break;
		}
		else
		{
			eg++;
			if (eg == 3)
			{
				printf("������������,�������ز˵�\n");
				Sleep(1500);
				break;
			}
			printf("����������������루����������������ν��Զ��ص��˵�����(%d/3)!��\n", 3 - eg);
		}
	}
}

/***************************************************/

void modify()
{
	int i, x, age1, num_idx = -1;
	char name2[20], sex1, num1[20], birth1[15], addr1[35], tel1[20], email1[20];
	printf("�����������޸ĵ�ѧ��ѧ��:");
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
		printf("���޴���");
		return; // false
	}
	EMP;
	printf("�Ƿ���Ҫ�޸�ѧ����ȫ����Ϣ(Y/N)\n");
	NEW
	{
		EMP;
		printf("�������µ�ѧ����Ϣ��\n����\t����\t�Ա�\tѧ��\t��������\t��ַ\t�绰\temail\t\n");
		scanf("%s\t%d\t%c\t%s\t%s\t%s\t%s\t%s", inform[num_idx].name, &inform[num_idx].age, &inform[num_idx].sex, inform[num_idx].num, inform[num_idx].birth, inform[num_idx].addr, inform[num_idx].tel, inform[num_idx].email);
	}
	else
	{
		printf("\n1.�޸�����\t2.�޸�����\t3.�޸��Ա�\t4.�޸�ѧ��\n5.�޸ĳ�������\t6.�޸ĵ�ַ\t7.�޸ĵ绰\t8.�޸�email\t9.�˳����˵�\n�������Ӳ˵���ţ�\n");
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			printf("�������µ�����:\n");
			scanf("%s", name2);
			strcpy(inform[num_idx].name, name2);
			break;
		case 2:
			printf("�������µ�����:\n");
			scanf("%d", &age1);
			inform[num_idx].age = age1;
			break;
		case 3:
			printf("�������µ��Ա�:\n");
			scanf("%c", &sex1);
			inform[num_idx].sex = sex1;
			break;
		case 4:
			printf("�������µ�ѧ��:\n");
			scanf("%s", num1);
			strcpy(inform[num_idx].num, num1);
			break;
		case 5:
			printf("�������µĳ�������:\n");
			scanf("%s", birth1);
			strcpy(inform[num_idx].birth, birth1);
			break;
		case 6:
			printf("�������µĵ�ַ:\n");
			scanf("%s", addr1);
			strcpy(inform[num_idx].addr, addr1);
			break;
		case 7:
			printf("�������µĵ绰:\n");
			scanf("%s", tel1);
			strcpy(inform[num_idx].tel, tel1);
			break;
		case 8:
			printf("�������µ�email:\n");
			scanf("%s", email1);
			strcpy(inform[num_idx].email, email1);
			break;
		case 9:
			printf("�������˵�");
			EMP;
			return; // false
		default:
			printf("����1-9֮��ѡ��\n");
		}
	}
	EMP;
	printf("�޸���ϣ�");
	return; // true
}
void dele()
{
	int i, j, k = 0;
	char num2[20];
	printf("������Ҫɾ��ѧ����ѧ��\n");

	scanf("%s", num2);

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
		EMP;
		printf("���޴���\n");
	}
	else
	{
		inform[0].age--;
		EMP;
		printf("�޸ĳɹ�,�Ƿ�鿴ɾ��������(Y/N)\n");

		NEW
		{
			EMP;
			output();
		}
	}
}
/***************************************************/
int msert(int n)
{
	int i, j;
	char s[20], sel, flag = 3;
	printf("��������Ҫ����λ�ø����˵�ѧ�ţ�\n");
	while (flag)
	{
		if (flag != 3)
			printf("����������(%d/3):\n", flag);
		scanf("%s", s);
		getchar();

		for (i = 1; i <= inform[0].age; i++)
		{
			if (strcmp(inform[i].num, s) == 0)
				break;
		}
		if (i == inform[0].age + 1)
		{
			printf("�������ѧ������,��ѧ��������!\n");
			flag--;
			if (!flag)
			{
				printf("�����쳣���������ز˵�!\n");
				Sleep(1500);
				return 0;
			}
			continue;
		}
		break;
	}
	flag = 3;
	printf("����������Ҫ�����뵽��ѧ��:\nA.ǰ��\tB.����\n");
	while (flag)
	{
		if (flag != 3)
			printf("����������(%d/3):\n", flag);
		scanf("%c", &sel);
		EMP;
		sel = toupper(sel);
		if (sel != 'A' && sel != 'B')
		{
			printf("�������ѡ������\n");
			flag--;
			if (!flag)
			{
				printf("�����쳣���������ز˵�!\n");
				Sleep(1500);
				return 0;
			}
			continue;
		}

		break;
	}
	// iΪ��ѧ��
	if (sel == 'A')
	{
		if (i == inform[0].age)
		{ // ����ѧ��Ϊ���һ����
			inform[i + n] = inform[i];
		}
		else
		{
		a:
			for (j = inform[0].age; j >= i; j--)
			{
				inform[j + n] = inform[j];
			}
		}
		printf("��������Ҫ����ѧ����Ϣ��\n");
		printf("\t	����\t����\t�Ա�(M/F)\tѧ��\t��������\t��ַ\t��ϵ��ʽ\temail\n");
		for (j = 0; j < n; j++)
		{
			printf("��%dλͬѧ:\t", j + 1);
			scanf("%s\t%d\t%c\t%s\t%s\t%s\t%s\t%s", inform[i + j].name, &inform[i + j].age, &inform[i + j].sex, inform[i + j].num, inform[i + j].birth, inform[i + j].addr, inform[i + j].tel, inform[i + j].email);
		}
		inform[0].age += j;
		return 1;
	}
	else
	{ /*�ں����������*/
		if (i == inform[0].age)
		{ // ����ѧ��Ϊ���һ����
			esert(n);
			return 1;
		}
		else
		{
			i++;
			goto a;
		}
	}
}

void esert(int n)
{
	int i;
	printf("��������Ҫ����ѧ����Ϣ��\n");
	printf("\t	����\t����\t�Ա�(M/F)\tѧ��\t��������\t��ַ\t��ϵ��ʽ\temail\n");
	for (i = 1; i <= n; i++)
	{
		printf("��%dλͬѧ:\t", i);
		scanf("%s\t%d\t%c\t%s\t%s\t%s\t%s\t%s", inform[inform[0].age + i].name, &inform[inform[0].age + i].age, &inform[inform[0].age + i].sex, inform[inform[0].age + i].num, inform[inform[0].age + i].birth, inform[inform[0].age + i].addr, inform[inform[0].age + i].tel, inform[inform[0].age + i].email);
	}
	inform[0].age += n;
	return;
}

void insert()
{
	int n, flag = 2, sum = 2, x = 2; //
	char str1;
	printf("��������Ҫ�����������(%d/100)\n", inform[0].age);
	while (x > 0)
	{
		if (x != 2)
			printf("���ٴ����룺\n");
		scanf("%d", &n);

		if (n > (100 - inform[0].age))
		{
			x--;
			if (x)
			{
				printf("�������������ڴ�������,��ȴ���������!(%d/2)\n", x);
				Sleep(1500);
			}
		}
		else
			x = -1;
		if (x == 0)
		{
			printf("�����쳣�������ز˵���\n");
			EMP;
			Sleep(1500);
			return;
		}
	}
	EMP;
	while (flag > 0)
	{
		if (flag == 2)
			printf("����������ģʽ(����):\n1.�м����\t2.������\t\n");
		else
			printf("���ٴ�����:\n");
		scanf("%c", &str1);

		if (str1 == '1' || str1 == '2')
		{
			if (str1 == '1')
			{
				if (!msert(n))
					return;
			}
			else
			{
				esert(n);
			}
			flag = 0;
			printf("����ɹ�!\n");
		}
		else
		{
			flag--;
			if (flag == 1)
				printf("������������,��ȴ����ԣ�(%d/2)\n", flag);
			else
			{
				printf("������������,��ȴ����ز˵���(%d/2)\n", flag);
				EMP;
				flag--;
			}
			Sleep(1500);
		}
	}
	if (flag == 0)
	{
		EMP;
		printf("�Ƿ�鿴���������(Y/N)\n");

		NEW
		{
			EMP;
			output();
		}
	}

	return;
}

void snum(char str2)
{

	int i, j, flag = 0;
	struct stu temp;
	for (i = 1; i <= inform[0].age - 1; i++)
	{
		for (j = 1; j <= inform[0].age - i; j++)
		{
			flag = 0;
			if ((str2 == 'A' && (strcmp(inform[j].num, inform[j + 1].num) > 0)) || (str2 == 'D' && strcmp(inform[j].num, inform[j + 1].num) < 0))
			{
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
	for (i = 1; i <= inform[0].age - 1; i++)
	{
		for (j = 1; j <= inform[0].age - i; j++)
		{
			flag = 0;
			if ((str2 == 'A' && (inform[j].age > inform[j + 1].age)) || (str2 == 'D' && (inform[j].age < inform[j + 1].age)))
			{
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
	for (i = 1; i <= inform[0].age - 1; i++)
	{
		for (j = 1; j <= inform[0].age - i; j++)
		{
			flag = 0;
			if ((str2 == 'A' && (strcmp(inform[j].birth, inform[j + 1].birth) > 0)) || (str2 == 'D' && strcmp(inform[j].birth, inform[j + 1].birth) < 0))
			{
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
	for (i = 1; i <= inform[0].age - 1; i++)
	{
		for (j = 1; j <= inform[0].age - i; j++)
		{
			flag = 0;
			if ((str2 == 'A' && (strcmp(inform[j].tel, inform[j + 1].tel) > 0)) || (str2 == 'D' && strcmp(inform[j].tel, inform[j + 1].tel) < 0))
			{
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
	char n = 5, flag = 2, sum = 0, x; //
	char str2;
	while (flag > 0)
	{
		if (flag == 2)
			printf("����������ģʽ(����)��\n1.ѧ��\t2.����\t3.��������\t4.��ϵ��ʽ\n");
		else
			printf("���ٴ����룺\n");
		scanf("%c", &n);
		EMP;
		if (n == '1' || n == '2' || n == '3' || n == '4')
		{
			printf("����ģʽ�Ƿ�ʹ��Ĭ������(Y/N)\n");
			NEW str2 = 'A';
			else str2 = 'D';
			EMP;
			if (n == '1')
				snum(str2);
			else if (n == '2')
				sage(str2);
			else if (n == '3')
				sbirth(str2);
			else
				stel(str2);
			flag = 0;
			printf("����ɹ�!\n");
		}
		else
		{
			flag--;
			if (flag == 1)
				printf("������������,��ȴ����ԣ�(%d/2)\n", flag);
			else
			{
				printf("������������,��ȴ����ز˵���(%d/2)\n", flag);
				flag--;
			}
			Sleep(1500);
		}
	}
	if (flag == 0)
	{
		printf("�Ƿ�鿴���������(Y/N)\n");
		NEW
		{
			EMP;
			output();
			return;
		}
	}

	return;
}
int main()
{

	system("color 71");
	menu();
	return 0;
}