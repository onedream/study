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
// 菜单
int getMenuChoice()
{
    int choice;
    cout << "请输入选项编号：";
    cin >> choice;
    while (getchar() != '\n')
        ; // 清除输入缓冲区
    return choice;
}
void menu()
{
    system("cls");      // 清屏
    system("color 74"); // 背景颜色
    printf("\n");
    cout << "\t\t\t\t*************************************************\n";
    cout << "\t\t\t\t*              诊所信息管理系统                 *\n";
    cout << "\t\t\t\t*************************************************\n";
    cout << "\t\t\t\t*                                               *\n";
    cout << "\t\t\t\t*              1. 录入信息                      *\n";
    cout << "\t\t\t\t*              2. 查询信息                      *\n";
    cout << "\t\t\t\t*              3. 账单记录                      *\n";
    cout << "\t\t\t\t*              4. 修改信息                      *\n";
    cout << "\t\t\t\t*              5. 输出总费用                    *\n";
    cout << "\t\t\t\t*              0. 退出系统                      *\n";
    cout << "\t\t\t\t*                                               *\n";
    cout << "\t\t\t\t*************************************************\n";
}
void menu_input()
{
    cout << "\t\t\t\t*************************************************\n";
    cout << "\t\t\t\t*                                               *\n";
    cout << "\t\t\t\t*              1.录入医生信息                   *\n";
    cout << "\t\t\t\t*              2.录入患者信息                   *\n";
    cout << "\t\t\t\t*                                               *\n";
    cout << "\t\t\t\t*************************************************\n";
}
void menu_search()
{
    cout << "\t\t\t\t*************************************************\n";
    cout << "\t\t\t\t*                                               *\n";
    cout << "\t\t\t\t*              1.查询医生                       *\n";
    cout << "\t\t\t\t*              2.查询患者                       *\n";
    cout << "\t\t\t\t*              3.输出所有医生的信息             *\n";
    cout << "\t\t\t\t*              4.输出所有患者的信息             *\n";
    cout << "\t\t\t\t*                                               *\n";
    cout << "\t\t\t\t*************************************************\n";
}
void menu_modify()
{
    cout << "\t\t\t\t*************************************************\n";
    cout << "\t\t\t\t*                                               *\n";
    cout << "\t\t\t\t*              1.修改医生信息                   *\n";
    cout << "\t\t\t\t*              2.修改患者信息                   *\n";
    cout << "\t\t\t\t*              3.删除医生信息                    *\n";
    cout << "\t\t\t\t*              4.删除患者信息                    *\n";
    cout << "\t\t\t\t*              5.删除所有医生信息                 *\n";
    cout << "\t\t\t\t*              6.删除所有患者信息                 *\n";
    cout << "\t\t\t\t*                                               *\n";
    cout << "\t\t\t\t*************************************************\n";
}
void menu_modify_doctor()
{
    cout << "\t\t\t\t*************************************************\n";
    cout << "\t\t\t\t*                                               *\n";
    cout << "\t\t\t\t*              1.修改医生姓名                   *\n";
    cout << "\t\t\t\t*              2.修改医生性别                   *\n";
    cout << "\t\t\t\t*              3.修改医生年龄                   *\n";
    cout << "\t\t\t\t*              4.修改医生号码                 *\n";
    cout << "\t\t\t\t*              5.修改医生诊费                   *\n";
    cout << "\t\t\t\t*              6.修改医生专业说明               *\n";
    cout << "\t\t\t\t*                                               *\n";
    cout << "\t\t\t\t*************************************************\n";
}
void menu_modify_patient()
{
    cout << "\t\t\t\t*************************************************\n";
    cout << "\t\t\t\t*                                               *\n";
    cout << "\t\t\t\t*              1.修改患者姓名                   *\n";
    cout << "\t\t\t\t*              2.修改患者性别                   *\n";
    cout << "\t\t\t\t*              3.修改患者年龄                   *\n";
    cout << "\t\t\t\t*              4.修改患者号码                 *\n";
    cout << "\t\t\t\t*              5.修改患者主治医生               *\n";
    cout << "\t\t\t\t*              6.修改患者诊费                   *\n";
    cout << "\t\t\t\t*                                               *\n";
    cout << "\t\t\t\t*************************************************\n";
}
// 录入信息
void input_doctor()
{
    int num, i;
    {
        cout << "请输入要添加医生信息的数量：";
        cin >> num;
        ofstream outfile("doctor.txt", ios::out | ios::app);
        if (!outfile)
            cout << "打开文件失败！" << endl;
        else
        {
            for (i = 1; i <= num; i++)
            {
                outfile << doctor.getname() << endl;
                outfile << doctor.getgender() << endl;
                outfile << doctor.getage() << endl;
                outfile << doctor.getnumber() << endl;
                outfile << doctor.getoffice_visit_fee() << endl;
                outfile << doctor.getspecially() << endl;
                outfile << endl;
                cout << endl;
            }
            outfile.close(); // 关闭文件
        }
    }
}
void input_patient()
{
    int num, i, t;
    string T;
    cout << "请输入想要添加患者信息的数量：";
    cin >> num;
    ofstream outfile("patient.txt", ios::out | ios::app);
    if (!outfile)
        cout << "打开文件失败！" << endl;
    else
    {
        for (i = 1; i <= num; i++)
        {
            T = patient.getname();
            bill.save_patient_name(T);
            outfile << T << endl;
            outfile << patient.getgender() << endl;
            outfile << patient.getage() << endl;
            outfile << patient.getnumber() << endl;
            T = patient.getdc_name();
            bill.save_doctor_name(T);
            outfile << T << endl;
            t = patient.getoffice_visit_fee();
            bill.save_office_visit_fee(t);
            outfile << t << endl;
            t = patient.getDrugFee();
            bill.save_drug_fee(t);
            outfile << t << endl;
            cout << endl;
        }
        outfile.close(); // 关闭文件
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
        cout << "输入错误，请重新输入。" << endl;
        fflush(stdin); // 清空输入缓冲区，避免读到错误的输入
        break;
    }
}
// 查询信息
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
        cout << "打开文件失败！";
        return;
    }
    while (infile >> name[i] >> gender[i] >> age[i] >> number[i] >> office_visit_fee[i] >> specially[i])
    {
        cout << "医生姓名：" << name[i] << endl;
        cout << "医生性别：" << gender[i] << endl;
        cout << "医生年龄：" << age[i] << endl;
        cout << "医生电话号码：" << number[i] << endl;
        cout << "医生诊费：" << office_visit_fee[i] << endl;
        cout << "医生专业：" << specially[i] << endl;
        cout << endl;
        ++i;
    }
}
void display_pa()
{
    int i = 0;
    ifstream infile("patient.txt", ios::in);
    if (!infile)
    {
        cout << "打开文件失败！";
        return;
    }
    while (infile >> name[i] >> gender[i] >> age[i] >> number[i] >> doctor_name[i] >> office_visit_fee[i] >> drug_fee[i])
    {
        cout << "患者姓名：" << name[i] << endl;
        cout << "性别：" << gender[i] << endl;
        cout << "年龄：" << age[i] << endl;
        cout << "电话号码：" << number[i] << endl;
        cout << "医生姓名：" << doctor_name[i] << endl;
        cout << "诊费：" << office_visit_fee[i] << endl;
        cout << "药费：" << drug_fee[i] << endl;
        cout << "总费用：" << office_visit_fee[i] + drug_fee[i] << endl;
        cout << endl;
        ++i;
    }
}
void display_bill()
{
    int i = 0, sum = 0;
    ifstream infile("bill.txt", ios::in);
    if (!infile)
    {
        cout << "打开文件失败！";
        return;
    }
    while (infile >> patient_name[i] >> doctor_name[i] >> office_visit_fee[i] >> drug_fee[i])
    {
        cout << "患者姓名：" << patient_name[i] << endl;
        cout << "医生姓名：" << doctor_name[i] << endl;
        cout << "诊费：" << office_visit_fee[i] << endl;
        cout << "药费：" << drug_fee[i] << endl;
        cout << "总费用：" << office_visit_fee[i] + drug_fee[i] << endl;
        sum += office_visit_fee[i] + drug_fee[i];
        cout << endl;
        ++i;
    }
    cout << "所有患者合计费用：" << sum << endl;
}
int search_pa_name(string na)
{
    int i = 0, flag;
    ifstream infile("patient.txt", ios::in);
    if (!infile)
    {
        cout << "打开文件失败！";
        return 0;
    }
    while (infile >> name[i] >> gender[i] >> age[i] >> number[i] >> doctor_name[i] >> office_visit_fee[i] >> drug_fee[i])
    {
        if (na == name[i])
        {
            cout << "患者姓名：" << name[i] << endl;
            cout << "性别：" << gender[i] << endl;
            cout << "年龄：" << age[i] << endl;
            cout << "电话号码：" << number[i] << endl;
            cout << "医生姓名：" << doctor_name[i] << endl;
            cout << "诊费：" << office_visit_fee[i] << endl;
            cout << "药费：" << drug_fee[i] << endl;
            cout << "总费用：" << office_visit_fee[i] + drug_fee[i] << endl;
            cout << endl;
            flag = i;
            return flag;
        }
        else
            ++i;
    }
    cout << "没有此患者" << endl;
    return -1;
}
int search_dc_name(string na)
{
    int i = 0, flag;
    ifstream infile("doctor.txt", ios::in);
    if (!infile)
    {
        cout << "打开文件失败！";
        return 0;
    }
    while (infile >> name[i] >> gender[i] >> age[i] >> number[i] >> office_visit_fee[i] >> specially[i])
    {
        if (na == name[i])
        {
            cout << "医生姓名：" << name[i] << endl;
            cout << "医生性别：" << gender[i] << endl;
            cout << "医生年龄：" << age[i] << endl;
            cout << "医生电话号码：" << number[i] << endl;
            cout << "医生诊费：" << office_visit_fee[i] << endl;
            cout << "医生专业：" << specially[i] << endl;
            cout << endl;
            flag = i;
            infile.close();
            return flag;
        }
        else
            ++i;
    }
    cout << "没有此医生" << endl;
    return -1;
}
void search()
{
    menu_search();
    string na;
    switch (getMenuChoice())
    {
    case 1:
        cout << "请输入医生的名字：";
        cin >> na;
        search_dc_name(na);
        break;
    case 2:
        cout << "请输入患者的名字：";
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
// 修改信息
void modify_doctor()
{
    string na;
    int i, sum = sum_dc();
    ;
    cout << "请输入要修改的医生姓名：";
    cin >> na;
    i = search_dc_name(na);
    if (i == -1)
        return;
    menu_modify_doctor();
    switch (getMenuChoice())
    {
    case 1:
        cout << "请输入新的医生姓名：";
        cin >> name[i];
        break;
    case 2:
        cout << "请输入新的医生性别：";
        cin >> gender[i];
        break;
    case 3:
        cout << "请输入新的医生年龄：";
        cin >> age[i];
        break;
    case 4:
        cout << "请输入新的医生电话号码：";
        cin >> number[i];
        break;
    case 5:
        cout << "请输入新的医生诊费：";
        cin >> office_visit_fee[i];
        break;
    case 6:
        cout << "请输入新的医生专业：";
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
    cout << "请输入要修改的患者姓名：";
    cin >> na;
    i = search_pa_name(na);
    if (i == -1)
        return;
    menu_modify_patient();
    switch (getMenuChoice())
    {
    case 1:
        cout << "请输入新的患者姓名：";
        cin >> name[i];
        break;
    case 2:
        cout << "请输入新的患者性别：";
        cin >> gender[i];
        break;
    case 3:
        cout << "请输入新的患者年龄：";
        cin >> age[i];
        break;
    case 4:
        cout << "请输入新的患者电话号码：";
        cin >> number[i];
        break;
    case 5:
        cout << "请输入新的患者医生姓名：";
        cin >> doctor_name[i];
        break;
    case 6:
        cout << "请输入新的患者诊费：";
        cin >> office_visit_fee[i];
        break;
    case 7:
        cout << "请输入新的患者药费：";
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
    cout << "请输入要删除的医生姓名：";
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
    cout << "请输入要删除的患者姓名：";
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
            cout << "所有病人总费用为：" << sum_fee() << endl;
            break;
        case 0:
            exit(0);
        default:
            cout << "输入错误，请重新输入。" << endl;
            fflush(stdin); // 清空输入缓冲区，避免读到错误的输入
            break;
        }
        system("pause");
    } while (1);
    return 0;
}
