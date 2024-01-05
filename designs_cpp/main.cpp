#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <cstring>
#include "person"
#define MAX 100

Doctor doctor;
Patient patient;
Bill bill;
string name[MAX], number[MAX], specially[MAX], doctor_name[MAX], patient_name[MAX];
double office_visit_fee[MAX], drug_fee[MAX];
char gender[MAX];
int age[MAX];
// �˵�
int getMenuChoice()
{
    int choice;
    cout << "������ѡ���ţ�";
    cin >> choice;
    while (getchar() != '\n')
        ; // ������뻺����
    return choice;
}
void menu()
{
    system("cls");      // ����
    system("color 74"); // ������ɫ
    printf("\n");
    cout << "\t\t\t\t*************************************************\n";
    cout << "\t\t\t\t*              ������Ϣ����ϵͳ                 *\n";
    cout << "\t\t\t\t*************************************************\n";
    cout << "\t\t\t\t*                                               *\n";
    cout << "\t\t\t\t*              1. ¼����Ϣ                      *\n";
    cout << "\t\t\t\t*              2. ��ѯ��Ϣ                      *\n";
    cout << "\t\t\t\t*              3. �˵���¼                      *\n";
    cout << "\t\t\t\t*              4. �޸���Ϣ                      *\n";
    cout << "\t\t\t\t*              5. ����ܷ���                    *\n";
    cout << "\t\t\t\t*              0. �˳�ϵͳ                      *\n";
    cout << "\t\t\t\t*                                               *\n";
    cout << "\t\t\t\t*************************************************\n";
}
void menu_input()
{
    cout << "\t\t\t\t*************************************************\n";
    cout << "\t\t\t\t*                                               *\n";
    cout << "\t\t\t\t*              1.¼��ҽ����Ϣ                   *\n";
    cout << "\t\t\t\t*              2.¼�뻼����Ϣ                   *\n";
    cout << "\t\t\t\t*                                               *\n";
    cout << "\t\t\t\t*************************************************\n";
}
void menu_search()
{
    cout << "\t\t\t\t*************************************************\n";
    cout << "\t\t\t\t*                                               *\n";
    cout << "\t\t\t\t*              1.��ѯҽ��                       *\n";
    cout << "\t\t\t\t*              2.��ѯ����                       *\n";
    cout << "\t\t\t\t*              3.�������ҽ������Ϣ             *\n";
    cout << "\t\t\t\t*              4.������л��ߵ���Ϣ             *\n";
    cout << "\t\t\t\t*                                               *\n";
    cout << "\t\t\t\t*************************************************\n";
}
void menu_modify()
{
    cout << "\t\t\t\t*************************************************\n";
    cout << "\t\t\t\t*                                               *\n";
    cout << "\t\t\t\t*              1.�޸�ҽ����Ϣ                   *\n";
    cout << "\t\t\t\t*              2.�޸Ļ�����Ϣ                   *\n";
    cout << "\t\t\t\t*              3.ɾ��ҽ����Ϣ                    *\n";
    cout << "\t\t\t\t*              4.ɾ��������Ϣ                    *\n";
    cout << "\t\t\t\t*              5.ɾ������ҽ����Ϣ                 *\n";
    cout << "\t\t\t\t*              6.ɾ�����л�����Ϣ                 *\n";
    cout << "\t\t\t\t*                                               *\n";
    cout << "\t\t\t\t*************************************************\n";
}
void menu_modify_doctor()
{
    cout << "\t\t\t\t*************************************************\n";
    cout << "\t\t\t\t*                                               *\n";
    cout << "\t\t\t\t*              1.�޸�ҽ������                   *\n";
    cout << "\t\t\t\t*              2.�޸�ҽ���Ա�                   *\n";
    cout << "\t\t\t\t*              3.�޸�ҽ������                   *\n";
    cout << "\t\t\t\t*              4.�޸�ҽ������                 *\n";
    cout << "\t\t\t\t*              5.�޸�ҽ�����                   *\n";
    cout << "\t\t\t\t*              6.�޸�ҽ��רҵ˵��               *\n";
    cout << "\t\t\t\t*                                               *\n";
    cout << "\t\t\t\t*************************************************\n";
}
void menu_modify_patient()
{
    cout << "\t\t\t\t*************************************************\n";
    cout << "\t\t\t\t*                                               *\n";
    cout << "\t\t\t\t*              1.�޸Ļ�������                   *\n";
    cout << "\t\t\t\t*              2.�޸Ļ����Ա�                   *\n";
    cout << "\t\t\t\t*              3.�޸Ļ�������                   *\n";
    cout << "\t\t\t\t*              4.�޸Ļ��ߺ���                 *\n";
    cout << "\t\t\t\t*              5.�޸Ļ�������ҽ��               *\n";
    cout << "\t\t\t\t*              6.�޸Ļ������                   *\n";
    cout << "\t\t\t\t*                                               *\n";
    cout << "\t\t\t\t*************************************************\n";
}
// ¼����Ϣ
void input_doctor()
{
    int num, i;
    {
        cout << "������Ҫ���ҽ����Ϣ��������";
        cin >> num;
        ofstream outfile("doctor.txt", ios::out | ios::app);
        if (!outfile)
            cout << "���ļ�ʧ�ܣ�" << endl;
        else
        {
            for (i = 1; i <= num; i++)
            {
                outfile << doctor.getname() << " ";
                outfile << doctor.getgender() << " ";
                outfile << doctor.getage() << " ";
                outfile << doctor.getnumber() << " ";
                outfile << doctor.getoffice_visit_fee() << " ";
                outfile << doctor.getspecially() << endl;
                //                outfile << endl;
                cout << endl;
            }
            outfile.close(); // �ر��ļ�
        }
    }
}
void input_patient()
{
    int num, i, t;
    string T;
    cout << "��������Ҫ��ӻ�����Ϣ��������";
    cin >> num;
    ofstream outfile("patient.txt", ios::out | ios::app);
    if (!outfile)
        cout << "���ļ�ʧ�ܣ�" << endl;
    else
    {
        for (i = 1; i <= num; i++)
        {
            T = patient.getname();
            bill.save_patient_name(T);
            outfile << T << " ";
            outfile << patient.getgender() << " ";
            outfile << patient.getage() << " ";
            outfile << patient.getnumber() << " ";
            T = patient.getdc_name();
            bill.save_doctor_name(T);
            outfile << T << " ";
            t = patient.getoffice_visit_fee();
            bill.save_office_visit_fee(t);
            outfile << t << " ";
            t = patient.getDrugFee();
            bill.save_drug_fee(t);
            outfile << t << endl;
            cout << endl;
        }
        outfile.close(); // �ر��ļ�
    }
}
void input()
{
    menu_input();
    switch (getMenuChoice())
    {
    case 1:
        input_doctor();
        break;
    case 2:
        input_patient();
        break;
    default:
        cout << "����������������롣" << endl;
        fflush(stdin); // ������뻺����������������������
        break;
    }
}
// ��ѯ��Ϣ
int sum_dc()
{
    int i = 0;
    ifstream infile("doctor.txt", ios::in);
    while (infile >> name[i] >> gender[i] >> age[i] >> number[i] >> office_visit_fee[i] >> specially[i])
        i++;
    infile.close();
    return i;
}
int sum_pa()
{
    int i = 0;
    ifstream infile("patient.txt", ios::in);
    while (infile >> name[i] >> gender[i] >> age[i] >> number[i] >> doctor_name[i] >> office_visit_fee[i] >> drug_fee[i])
        i++;
    infile.close();
    return i;
}
int sum_fee()
{
    int i = 0, sum = 0;
    ifstream infile("bill.txt", ios::in);
    while (infile >> patient_name[i] >> doctor_name[i] >> office_visit_fee[i] >> drug_fee[i])
    {
        sum += office_visit_fee[i] + drug_fee[i];
        i++;
    }
    infile.close();
    return sum;
}
void display_dc()
{
    int i = 0;
    ifstream infile("doctor.txt", ios::in);
    if (!infile)
    {
        cout << "���ļ�ʧ�ܣ�";
        return;
    }
    char c;
    infile >> c;
    if (infile.eof())
    {
        cout << "δ��ѯ����Ϣ��" << endl;
        infile.close();
        return;
    }
    cout << "--------------------------------------------------------------" << endl;
    cout << "����"
         << "\t"
         << "�Ա�"
         << "\t"
         << "����"
         << "\t"
         << "�绰����"
         << "\t"
         << "���"
         << "\t"
         << "רҵ" << endl;
    cout << "--------------------------------------------------------------" << endl;
    while (infile >> name[i] >> gender[i] >> age[i] >> number[i] >> office_visit_fee[i] >> specially[i])
    {
        cout << name[i] << "\t" << gender[i] << "\t" << age[i] << "\t" << number[i] << "\t" << office_visit_fee[i] << "\t" << specially[i] << endl;
        cout << "--------------------------------------------------------------" << endl;
        ++i;
    }
    cout << endl;
}
void display_pa()
{
    int i = 0;
    ifstream infile("patient.txt", ios::in);
    if (!infile)
    {
        cout << "���ļ�ʧ�ܣ�";
        return;
    }
    char c;
    infile >> c;
    if (infile.eof())
    {
        cout << "δ��ѯ����Ϣ��" << endl;
        infile.close();
        return;
    }
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "����"
         << "\t"
         << "�Ա�"
         << "\t"
         << "����"
         << "\t"
         << "�绰����"
         << "\t"
         << "����ҽ��"
         << "\t"
         << "���"
         << "\t"
         << "ҩ��"
         << "\t"
         << "�ܷ���" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    while (infile >> name[i] >> gender[i] >> age[i] >> number[i] >> doctor_name[i] >> office_visit_fee[i] >> drug_fee[i])
    {
        cout << name[i] << "\t" << gender[i] << "\t" << age[i] << "\t" << number[i] << "\t" << doctor_name[i] << "\t\t" << office_visit_fee[i] << "\t" << drug_fee[i] << "\t" << office_visit_fee[i] + drug_fee[i] << endl;
        cout << "------------------------------------------------------------------------------" << endl;
        ++i;
    }
    cout << endl;
}
void display_bill()
{
    int i = 0, sum = 0;
    ifstream infile("bill.txt", ios::in);
    if (!infile)
    {
        cout << "���ļ�ʧ�ܣ�";
        return;
    }
    char c;
    infile >> c;
    if (infile.eof())
    {
        cout << "δ��ѯ����Ϣ��" << endl;
        infile.close();
        return;
    }
    cout << "----------------------------------------------------------" << endl;
    cout << "��������"
         << "\t"
         << "ҽ������"
         << "\t"
         << "���"
         << "\t"
         << "ҩ��"
         << "\t"
         << "�ܷ���" << endl;
    cout << "----------------------------------------------------------" << endl;
    while (infile >> patient_name[i] >> doctor_name[i] >> office_visit_fee[i] >> drug_fee[i])
    {
        cout << patient_name[i] << "\t\t" << doctor_name[i] << "\t\t" << office_visit_fee[i] << "\t" << drug_fee[i] << "\t" << office_visit_fee[i] + drug_fee[i] << endl;
        cout << "----------------------------------------------------------" << endl;
        sum += office_visit_fee[i] + drug_fee[i];
        ++i;
    }
    cout << "���л��ߺϼƷ��ã�" << sum << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << endl;
}
int search_pa_name(string na)
{
    int i = 0, flag;
    ifstream infile("patient.txt", ios::in);
    if (!infile)
    {
        cout << "���ļ�ʧ�ܣ�";
        return 0;
    }
    while (infile >> name[i] >> gender[i] >> age[i] >> number[i] >> doctor_name[i] >> office_visit_fee[i] >> drug_fee[i])
    {
        if (na == name[i])
        {
            cout << "------------------------------------------------------------------------------" << endl;
            cout << "����"
                 << "\t"
                 << "�Ա�"
                 << "\t"
                 << "����"
                 << "\t"
                 << "�绰����"
                 << "\t"
                 << "����ҽ��"
                 << "\t"
                 << "���"
                 << "\t"
                 << "ҩ��"
                 << "\t"
                 << "�ܷ���" << endl;
            cout << "------------------------------------------------------------------------------" << endl;
            cout << name[i] << "\t" << gender[i] << "\t" << age[i] << "\t" << number[i] << "\t" << doctor_name[i] << "\t\t" << office_visit_fee[i] << "\t" << drug_fee[i] << "\t" << office_visit_fee[i] + drug_fee[i] << endl;
            cout << "------------------------------------------------------------------------------" << endl;
            cout << endl;
            flag = i;
            return flag;
        }
        else
            ++i;
    }
    cout << "û�д˻���" << endl;
    return -1;
}
int search_dc_name(string na)
{
    int i = 0, flag;
    ifstream infile("doctor.txt", ios::in);
    if (!infile)
    {
        cout << "���ļ�ʧ�ܣ�";
        return 0;
    }
    while (infile >> name[i] >> gender[i] >> age[i] >> number[i] >> office_visit_fee[i] >> specially[i])
    {
        if (na == name[i])
        {
            cout << "--------------------------------------------------------------" << endl;
            cout << "����"
                 << "\t"
                 << "�Ա�"
                 << "\t"
                 << "����"
                 << "\t"
                 << "�绰����"
                 << "\t"
                 << "���"
                 << "\t"
                 << "רҵ" << endl;
            cout << "--------------------------------------------------------------" << endl;
            cout << name[i] << "\t" << gender[i] << "\t" << age[i] << "\t" << number[i] << "\t" << office_visit_fee[i] << "\t" << specially[i] << endl;
            cout << "--------------------------------------------------------------" << endl;
            cout << endl;
            flag = i;
            infile.close();
            return flag;
        }
        else
            ++i;
    }
    cout << "û�д�ҽ��" << endl;
    return -1;
}
void search()
{
    menu_search();
    string na;
    switch (getMenuChoice())
    {
    case 1:
        cout << "������ҽ�������֣�";
        cin >> na;
        search_dc_name(na);
        break;
    case 2:
        cout << "�����뻼�ߵ����֣�";
        cin >> na;
        search_pa_name(na);
        break;
    case 3:
        display_dc();
        break;
    case 4:
        display_pa();
        break;
    default:
        break;
    }
}
// �޸���Ϣ
void modify_doctor()
{
    string na;
    int i, sum = sum_dc();
    ;
    cout << "������Ҫ�޸ĵ�ҽ��������";
    cin >> na;
    i = search_dc_name(na);
    if (i == -1)
        return;
    menu_modify_doctor();
    switch (getMenuChoice())
    {
    case 1:
        cout << "�������µ�ҽ��������";
        cin >> name[i];
        break;
    case 2:
        cout << "�������µ�ҽ���Ա�";
        cin >> gender[i];
        break;
    case 3:
        cout << "�������µ�ҽ�����䣺";
        cin >> age[i];
        break;
    case 4:
        cout << "�������µ�ҽ���绰���룺";
        cin >> number[i];
        break;
    case 5:
        cout << "�������µ�ҽ����ѣ�";
        cin >> office_visit_fee[i];
        break;
    case 6:
        cout << "�������µ�ҽ��רҵ��";
        cin >> specially[i];
        break;
    default:
        break;
    }
    ofstream outfile("doctor.txt");
    i = 0;
    while (i < sum)
    {
        outfile << name[i] << " " << gender[i] << " " << age[i] << " " << number[i] << " " << office_visit_fee[i] << " " << specially[i] << endl;
        i++;
    }
    outfile.close();
}
void modify_patient()
{
    string na;
    int i, sum = sum_pa();
    cout << "������Ҫ�޸ĵĻ���������";
    cin >> na;
    i = search_pa_name(na);
    if (i == -1)
        return;
    menu_modify_patient();
    switch (getMenuChoice())
    {
    case 1:
        cout << "�������µĻ���������";
        cin >> name[i];
        break;
    case 2:
        cout << "�������µĻ����Ա�";
        cin >> gender[i];
        break;
    case 3:
        cout << "�������µĻ������䣺";
        cin >> age[i];
        break;
    case 4:
        cout << "�������µĻ��ߵ绰���룺";
        cin >> number[i];
        break;
    case 5:
        cout << "�������µĻ���ҽ��������";
        cin >> doctor_name[i];
        break;
    case 6:
        cout << "�������µĻ�����ѣ�";
        cin >> office_visit_fee[i];
        break;
    case 7:
        cout << "�������µĻ���ҩ�ѣ�";
        cin >> drug_fee[i];
        break;
    default:
        break;
    }
    ofstream outfile("patient.txt");
    i = 0;
    while (i < sum)
    {
        outfile << name[i] << " " << gender[i] << " " << age[i] << " " << number[i] << " " << doctor_name[i] << " " << office_visit_fee[i] << " " << drug_fee[i] << endl;
        i++;
    }
}
void delete_doctor()
{
    string na;
    int i = 0, sum, flag;
    cout << "������Ҫɾ����ҽ��������";
    cin >> na;
    flag = search_dc_name(na);
    sum = sum_dc();
    ofstream outfile("doctor.txt");
    while (i < sum)
    {
        if (i == flag)
        {
            i++;
            continue;
        }
        outfile << name[i] << " " << gender[i] << " " << age[i] << " " << number[i] << " " << office_visit_fee[i] << " " << specially[i] << endl;
        i++;
    }
    outfile.close();
}
void delete_patient()
{
    string na;
    int i = 0, sum, flag;
    cout << "������Ҫɾ���Ļ���������";
    cin >> na;
    flag = search_pa_name(na);
    sum = sum_pa();
    ofstream outfile("patient.txt");
    while (i < sum)
    {
        if (i == flag)
        {
            i++;
            continue;
        }
        outfile << name[i] << " " << gender[i] << " " << age[i] << " " << number[i] << " " << doctor_name[i] << " " << office_visit_fee[i] << " " << drug_fee[i] << endl;
        i++;
    }
    outfile.close();
}
void delete_all_doctor()
{
    ofstream outfile("doctor.txt");
    outfile.close();
}
void delete_all_patient()
{
    ofstream outfile("patient.txt");
    outfile.close();
}
void modify()
{
    menu_modify();
    switch (getMenuChoice())
    {
    case 1:
        modify_doctor();
        break;
    case 2:
        modify_patient();
        break;
    case 3:
        delete_doctor();
        break;
    case 4:
        delete_patient();
        break;
    case 5:
        delete_all_doctor();
        break;
    case 6:
        delete_all_patient();
        break;
    default:
        break;
    }
}
int main()
{
    int choice;
    do
    {
        menu();
        switch (getMenuChoice())
        {
        case 1:
            input();
            break;
        case 2:
            search();
            break;
        case 3:
            display_bill();
            break;
        case 4:
            modify();
            break;
        case 5:
            cout << "���в����ܷ���Ϊ��" << sum_fee() << endl;
            break;
        case 0:
            exit(0);
        default:
            cout << "����������������롣" << endl;
            fflush(stdin); // ������뻺����������������������
            break;
        }
        system("pause");
    } while (1);
    return 0;
}
