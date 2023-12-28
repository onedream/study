#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <cstring>
#define MAX 100
#define doctor_txt_path "D:\\Work_folder\\study\\study\\designs_cpp\\doctor.txt"
#define patient_txt_path "D:\\Work_folder\\study\\study\\designs_cpp\\patient.txt"
#define bill_txt_path "D:\\Work_folder\\study\\study\\designs_cpp\\bill.txt"
// 人类
class Person
{
public:
    Person() {}
    ~Person() {} // 析构函数
    double getage();
    char getgender();
    string getname();
    string getnumber();
    string getaddress();

protected:
    string name;
    string number;
    string address;
    char gender;
    int age;
};
double Person::getage()
{
    cout << "年龄：";
    cin >> age;
    if (age < 0)
    {
        cout << "请重新输入：";
        cin >> age;
        if (age < 0)
            cout << "输入错误！" << endl;
        else
        {
            cout<<"输入成功！"<<endl;
            return age;
        }
    }
    else
    {
            cout << "输入成功！" << endl;
            return age;
    }
    cout<<"输入错误！"<<endl;
    return -1;
}
string Person::getname()
{
    cout << "姓名：";
    cin >> name;
    if (name == "")
    {
        cout << "请重新输入：";
        cin >> name;
        if (name == "")
            cout << "输入错误！" << endl;
        else
        {
            cout << "输入成功！" << endl;
            cout << "姓名：" << name << endl;
            return name;
        }
    }
    else
    {
        cout << "输入成功！" << endl;
        cout << "姓名：" << name << endl;
    }
    return name;
}
string Person::getnumber()
{
    cout << "电话号码：";
    cin >> number;
    if (number == "")
    {
        cout << "请重新输入：";
        cin >> number;
        if (number == "")
            cout << "输入错误！" << endl;
        else
        {
            cout << "输入成功！" << endl;
            cout << "电话号码：" << number << endl;
            return number;
        }
    }
    else
    {
        cout << "输入成功！" << endl;
        return number;
    }
    cout<<"输入错误"<<endl;
    return "-1";
}
string Person::getaddress()
{
    cout << "地址：";
    cin >> address;
    if (address == "")
    {
        cout << "请重新输入：";
        cin >> address;
        if (address == "")
        {
            cout << "输入错误！" << endl;
        }
        else
        {
            cout << "输入成功！" << endl;
            cout << "地址：" << address << endl;
            return address;
        }
    }
    else
    {
        cout << "输入成功！" << endl;
        cout << "地址：" << address << endl;
        return address;
    }
    cout<<"输入错误"<<endl;
    return "-1";
}
char Person::getgender()
{
    cout << "性别：";
    cin >> gender;
    if (gender == 'M' || gender == 'F')
    {
        cout << "输入成功！" << endl;
        return gender;
        cout << "输入错误！" << endl;
        return 'M';
    }
    else
    {
        cout << "输入成功！" << endl;
        return gender;
    }
    cout<<"输入错误"<<endl;
    cout<<"默认为M"<<endl;
    return 'M';
}
// 医生类
class Doctor : public Person
{
private:
    string specially; // 专业说明
    double office_visit_fee; // 诊费
public:
    Doctor() {}
    string getspecially();
    double getoffice_visit_fee();
    void display();
}; 
string Doctor::getspecially()
{
    cout << "请输入医生的专业：";
    cin >> specially;
    if (specially == "")
    {
        cout << "请重新输入：";
        cin >> specially;
        if (specially == "")
            cout << "输入错误！" << endl;
        else
        {
            cout << "输入成功！" << endl;
            return specially;
        }
    }
    else
    {
        cout << "输入成功！" << endl;
        return specially;
    }
    cout<<"输入错误"<<endl;
    return "-1";
}
double Doctor::getoffice_visit_fee()
{
    cout << "诊费：";
    cin >> office_visit_fee;
    if (office_visit_fee < 0)
    {
        cout << "请重新输入：";
        cin >> office_visit_fee;
        if (office_visit_fee < 0)
        {
            cout << "输入错误！" << endl;
            return -1;
        }
        else
        {
            cout << "输入成功！" << endl;
            return office_visit_fee;
        }
    }
    else
    {
        cout << "输入成功！" << endl;
        return office_visit_fee;
    }
}
void Doctor::display()
{
    string name[MAX];
    string number[MAX];
    string address[MAX];
    string specially[MAX];
    char gender[MAX];
    int age[MAX],i=0;
    double office_visit_fee[MAX];
    ifstream infile(doctor_txt_path, ios::in);
    if (!infile)
    {
        cout << "打开文件失败！";
        return;
    }
    while(infile>>name[i]>>gender[i]>>age[i]>>number[i]>>office_visit_fee[i]>>specially[i]>>address[i])
    {
        cout << "医生姓名：" << name[i] << endl;
        cout << "医生性别：" << gender[i] << endl;  
        cout << "医生年龄：" << age[i] << endl;
        cout << "医生电话号码：" << number[i] << endl;
        cout << "医生诊费：" << office_visit_fee[i] << endl;
        cout << "医生专业：" << specially[i] << endl;
        cout << "医生地址：" << address[i] << endl;
        i++;
    }
}

// 患者类
class Patient : public Person
{
private:
    string dc_name;
    double drug_fee; // 药费
    double office_visit_fee; // 诊费
public:
    double getoffice_visit_fee();
    double getDrugFee();
    string getdc_name();
    void display();
};
double Patient::getoffice_visit_fee()
{
    cout << "诊费：";
    cin >> office_visit_fee;
    if (office_visit_fee < 0)
    {
        cout << "请重新输入：";
        cin >> office_visit_fee;
        if (office_visit_fee < 0)
            cout << "输入错误！" << endl;
        else
        {
            cout << "输入成功！" << endl;
            cout << "诊费：" << office_visit_fee << endl;
            return office_visit_fee;
        }
    }
    else
    {
        cout << "输入成功！" << endl;
        cout << "诊费：" << office_visit_fee << endl;
        return office_visit_fee;
    }
    cout<<"输入错误"<<endl;
    return -1;
};
double Patient::getDrugFee()
{
    cout << "药费：";
    cin >> drug_fee;
    if (drug_fee < 0)
    {
        cout << "请重新输入：";
        cin >> drug_fee;
        if (drug_fee < 0)
        {
            cout << "输入错误！" << endl;
        }
        else
        {
            cout << "输入成功！" << endl;
            cout << "药费：" << drug_fee << endl;
            return drug_fee;
        }
    }
    else
    {
        cout << "输入成功！" << endl;
        cout << "药费：" << drug_fee << endl;
        return drug_fee;
    }
    cout<<"输入错误"<<endl;
    return -1;
};
string Patient::getdc_name()
{
    cout << "该患者医生姓名：";
    cin >> dc_name;
    if (dc_name == " ")
    {
        cout << "请重新输入：";
        cin >> dc_name;
        if (dc_name == " ")
            cout << "输入错误！" << endl;
        else
        {
            cout << "输入成功！" << endl;
            cout << "医生姓名：" << dc_name << endl;
            return dc_name;
        }
    }
    else
    {
        cout << "输入成功！" << endl;
        cout << "姓名：" << dc_name << endl;
    }
    return dc_name;
}
void Patient::display()
{
    string name[MAX];
    string address[MAX];
    string doctor_name[MAX];
    string patient_name[MAX];
    string number[MAX];
    double office_visit_fee[MAX];
    double drug_fee[MAX];
    char gender[MAX];
    int age[MAX],i=0;
    ifstream infile(patient_txt_path, ios::in);
    if (!infile)
    {
        cout << "打开文件失败！";
        return;
    }
    while(infile>>name[i]>>gender[i]>>age[i]>>number[i]>>address[i]>>doctor_name[i]>>office_visit_fee[i]>>drug_fee[i])
    {
        cout << "患者姓名：" << name[i] << endl;
        cout << "性别："<< gender[i] << endl;
        cout << "年龄：" << age[i] << endl;
        cout << "电话号码：" << number[i] << endl;
        cout << "地址：" << address[i] << endl;
        cout << "医生姓名：" << doctor_name[i] << endl;
        cout << "诊费：" << office_visit_fee[i] << endl;
        cout << "药费：" << drug_fee[i] << endl;
        cout << "总费用：" << office_visit_fee[i] + drug_fee[i] << endl;
        i++;
    }
}

class Bill 
{
    public:
    void save_doctor_name(string);
    void save_patient_name(string);
    void save_office_visit_fee(double);
    void save_drug_fee(double);
    void display();
    private:
    string doctor_name;
    string patient_name;
    double office_visit_fee;
    double drug_fee;
};
void Bill::save_doctor_name(string Doctor_name)
{
    ofstream outfile(bill_txt_path, ios::out | ios::app);
    if (!outfile)
    {
        cout << "打开bill.txt文件失败！" << endl;
        return;
    }
    doctor_name = Doctor_name;
    outfile << doctor_name << " ";
    outfile.close(); // 关闭文件
}
void Bill::save_patient_name(string Patient_name)
{
    ofstream outfile(bill_txt_path, ios::out | ios::app);
    if (!outfile)
    {
        cout << "打开bill.txt文件失败！" << endl;
        return;
    }
    patient_name = Patient_name;
    outfile << patient_name << " ";
    outfile.close(); // 关闭文件
}
void Bill::save_office_visit_fee(double Office_visit_fee)
{
    ofstream outfile(bill_txt_path, ios::out | ios::app);
    if (!outfile)
    {
        cout << "打开bill.txt文件失败！" << endl;
        return;
    }
    office_visit_fee = Office_visit_fee;
    outfile << office_visit_fee << " ";
    outfile.close(); // 关闭文件
}
void Bill::save_drug_fee(double Drug_fee)
{
    ofstream outfile(bill_txt_path, ios::out | ios::app);
    if (!outfile)
    {
        cout << "打开bill.txt文件失败！" << endl;
        return;
    }
    drug_fee = Drug_fee;
    outfile << drug_fee << " ";
    outfile.close(); // 关闭文件
}
void Bill::display()
{
    string doctor_name[MAX];
    string patient_name[MAX];
    double office_visit_fee[MAX];
    double drug_fee[MAX];
    int i=0,sum;
    ifstream infile(bill_txt_path, ios::in);
    if (!infile)
    {
        cout << "打开文件失败！";
        return;
    }
    while(infile>>patient_name[i]>>doctor_name[i]>>office_visit_fee[i]>>drug_fee[i])
    {
        cout << "患者姓名：" << patient_name[i] << endl;
        cout << "医生姓名：" << doctor_name[i] << endl;
        cout << "诊费：" << office_visit_fee[i] << endl;
        cout << "药费：" << drug_fee[i] << endl;
        cout << "总费用：" << office_visit_fee[i]+drug_fee[i]<< endl<<endl;
        i++;
    }
    cout<<"所有患者合计费用："<<sum<<endl;
}

Doctor doctor;
Patient patient;
Bill bill;

void input_1()
{
    int num,i;
    {
        cout << "请输入要添加医生信息的数量：";
        cin >> num;
        ofstream outfile(doctor_txt_path, ios::out | ios::app);
        if (!outfile)
            cout << "打开文件失败！" << endl;
        else
        {
            for (i = 1; i <= num; i++)
            {
                outfile<<doctor.getname()<<' ';
                outfile<<doctor.getgender()<<' ';
                outfile<<doctor.getage()<<' ';
                outfile<<doctor.getnumber()<<' ';
                outfile<<doctor.getoffice_visit_fee()<<' ';
                outfile<<doctor.getspecially()<<' ';
                outfile<<doctor.getaddress()<<' ';
            }
            outfile.close(); // 关闭文件
        }
    }
}
void input_2()
{
    int num,i,t;
    string T;
    cout << "请输入想要添加患者信息的数量：";
    cin >> num;
    ofstream outfile(patient_txt_path, ios::out | ios::app);
    if (!outfile)
        cout << "打开文件失败！" << endl;
    else
    {
        for (i = 1; i <= num; i++)
        {
            T=patient.getname();
            outfile<<T<<' ';
            bill.save_patient_name(T);
            outfile<<patient.getgender()<<' ';
            outfile<<patient.getage()<<' ';
            outfile<<patient.getnumber()<<' ';
            outfile<<patient.getaddress()<<' ';
            T=patient.getdc_name();
            outfile<<T<<' ';
            bill.save_doctor_name(T);
            t=patient.getoffice_visit_fee();
            outfile<<t<<' ';
            bill.save_office_visit_fee(t);
            t=patient.getDrugFee();
            outfile<<t<<' ';
            bill.save_drug_fee(t);
        }
        outfile.close(); // 关闭文件
    }
}
int getMenuChoice()
{
    int choice;
    cout << "请输入选项编号：";
    cin >> choice;
    while (getchar() != '\n')
        ; // 清除输入缓冲区
    return choice;
}
// 菜单
void menu()
{
    system("cls");      // 清屏
    system("color 74"); // 背景颜色
    printf("\n");
    cout << "\t\t\t\t************************************************\n";
    cout << "\t\t\t\t*              诊所信息管理系统                *\n";
    cout << "\t\t\t\t************************************************\n";
    cout << "\t\t\t\t*                                              *\n";
    cout << "\t\t\t\t*              1. 录入信息                      *\n";
    cout << "\t\t\t\t*              2. 查询信息                      *\n";
    cout << "\t\t\t\t*              3. 修改信息                      *\n";
    cout << "\t\t\t\t*              4. 输出账单                      *\n";
    cout << "\t\t\t\t*              0. 退出系统                      *\n";
}
void menu_search()
{
    cout << "\t\t\t\t************************************************\n";
    cout << "\t\t\t\t*                                              *\n";
    cout << "\t\t\t\t*              1.医生记录                       *\n";
    cout << "\t\t\t\t*              2.患者记录                       *\n";
    cout << "\t\t\t\t*              3.账单记录                       *\n";
}
void menu_input()
{
    cout << "\t\t\t\t************************************************\n";
    cout << "\t\t\t\t*                                              *\n";
    cout << "\t\t\t\t*              1.录入医生信息                    *\n";
    cout << "\t\t\t\t*              2.录入患者信息                    *\n";
}
// 录入信息
void input(){
    menu_input();
    switch (getMenuChoice())
    {
        case 1:
            input_1();
            break;
        case 2:
            input_2();
            break;
        default:
            cout << "输入错误，请重新输入。" << endl;
            fflush(stdin); // 清空输入缓冲区，避免读到错误的输入
            break;
    }
}
// 查询信息
void search()
{
    ifstream infile(doctor_txt_path, ios::in); // 打开文件
    if (!infile)/* condition */
    {
        cout << "打开文件失败！" << endl;
        return;
    }
    menu_search();
    switch (getMenuChoice())
    {
    case 1:
        doctor.display();
    break;
    case 2:
        patient.display();
    break;
    case 3:
        bill.display();
    break;
    default:
        break;
    }
}
// 修改信息
void modify()
{

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
