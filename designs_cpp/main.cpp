#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <cstring>
#define MAX 100
#define doctor_txt_path "D:\\Work_folder\\study\\study\\designs_cpp\\doctor.txt"
#define patient_txt_path "D:\\Work_folder\\study\\study\\designs_cpp\\patient.txt"
#define bill_txt_path "D:\\Work_folder\\study\\study\\designs_cpp\\bill.txt"
// ����
class Person
{
public:
    Person() {}
    ~Person() {} // ��������
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
    cout << "���䣺";
    cin >> age;
    if (age < 0)
    {
        cout << "���������룺";
        cin >> age;
        if (age < 0)
            cout << "�������" << endl;
        else
        {
            cout<<"����ɹ���"<<endl;
            return age;
        }
    }
    else
    {
            cout << "����ɹ���" << endl;
            return age;
    }
    cout<<"�������"<<endl;
    return -1;
}
string Person::getname()
{
    cout << "������";
    cin >> name;
    if (name == "")
    {
        cout << "���������룺";
        cin >> name;
        if (name == "")
            cout << "�������" << endl;
        else
        {
            cout << "����ɹ���" << endl;
            cout << "������" << name << endl;
            return name;
        }
    }
    else
    {
        cout << "����ɹ���" << endl;
        cout << "������" << name << endl;
    }
    return name;
}
string Person::getnumber()
{
    cout << "�绰���룺";
    cin >> number;
    if (number == "")
    {
        cout << "���������룺";
        cin >> number;
        if (number == "")
            cout << "�������" << endl;
        else
        {
            cout << "����ɹ���" << endl;
            cout << "�绰���룺" << number << endl;
            return number;
        }
    }
    else
    {
        cout << "����ɹ���" << endl;
        return number;
    }
    cout<<"�������"<<endl;
    return "-1";
}
string Person::getaddress()
{
    cout << "��ַ��";
    cin >> address;
    if (address == "")
    {
        cout << "���������룺";
        cin >> address;
        if (address == "")
        {
            cout << "�������" << endl;
        }
        else
        {
            cout << "����ɹ���" << endl;
            cout << "��ַ��" << address << endl;
            return address;
        }
    }
    else
    {
        cout << "����ɹ���" << endl;
        cout << "��ַ��" << address << endl;
        return address;
    }
    cout<<"�������"<<endl;
    return "-1";
}
char Person::getgender()
{
    cout << "�Ա�";
    cin >> gender;
    if (gender == 'M' || gender == 'F')
    {
        cout << "����ɹ���" << endl;
        return gender;
        cout << "�������" << endl;
        return 'M';
    }
    else
    {
        cout << "����ɹ���" << endl;
        return gender;
    }
    cout<<"�������"<<endl;
    cout<<"Ĭ��ΪM"<<endl;
    return 'M';
}
// ҽ����
class Doctor : public Person
{
private:
    string specially; // רҵ˵��
    double office_visit_fee; // ���
public:
    Doctor() {}
    string getspecially();
    double getoffice_visit_fee();
    void display();
}; 
string Doctor::getspecially()
{
    cout << "������ҽ����רҵ��";
    cin >> specially;
    if (specially == "")
    {
        cout << "���������룺";
        cin >> specially;
        if (specially == "")
            cout << "�������" << endl;
        else
        {
            cout << "����ɹ���" << endl;
            return specially;
        }
    }
    else
    {
        cout << "����ɹ���" << endl;
        return specially;
    }
    cout<<"�������"<<endl;
    return "-1";
}
double Doctor::getoffice_visit_fee()
{
    cout << "��ѣ�";
    cin >> office_visit_fee;
    if (office_visit_fee < 0)
    {
        cout << "���������룺";
        cin >> office_visit_fee;
        if (office_visit_fee < 0)
        {
            cout << "�������" << endl;
            return -1;
        }
        else
        {
            cout << "����ɹ���" << endl;
            return office_visit_fee;
        }
    }
    else
    {
        cout << "����ɹ���" << endl;
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
        cout << "���ļ�ʧ�ܣ�";
        return;
    }
    while(infile>>name[i]>>gender[i]>>age[i]>>number[i]>>office_visit_fee[i]>>specially[i]>>address[i])
    {
        cout << "ҽ��������" << name[i] << endl;
        cout << "ҽ���Ա�" << gender[i] << endl;  
        cout << "ҽ�����䣺" << age[i] << endl;
        cout << "ҽ���绰���룺" << number[i] << endl;
        cout << "ҽ����ѣ�" << office_visit_fee[i] << endl;
        cout << "ҽ��רҵ��" << specially[i] << endl;
        cout << "ҽ����ַ��" << address[i] << endl;
        i++;
    }
}

// ������
class Patient : public Person
{
private:
    string dc_name;
    double drug_fee; // ҩ��
    double office_visit_fee; // ���
public:
    double getoffice_visit_fee();
    double getDrugFee();
    string getdc_name();
    void display();
};
double Patient::getoffice_visit_fee()
{
    cout << "��ѣ�";
    cin >> office_visit_fee;
    if (office_visit_fee < 0)
    {
        cout << "���������룺";
        cin >> office_visit_fee;
        if (office_visit_fee < 0)
            cout << "�������" << endl;
        else
        {
            cout << "����ɹ���" << endl;
            cout << "��ѣ�" << office_visit_fee << endl;
            return office_visit_fee;
        }
    }
    else
    {
        cout << "����ɹ���" << endl;
        cout << "��ѣ�" << office_visit_fee << endl;
        return office_visit_fee;
    }
    cout<<"�������"<<endl;
    return -1;
};
double Patient::getDrugFee()
{
    cout << "ҩ�ѣ�";
    cin >> drug_fee;
    if (drug_fee < 0)
    {
        cout << "���������룺";
        cin >> drug_fee;
        if (drug_fee < 0)
        {
            cout << "�������" << endl;
        }
        else
        {
            cout << "����ɹ���" << endl;
            cout << "ҩ�ѣ�" << drug_fee << endl;
            return drug_fee;
        }
    }
    else
    {
        cout << "����ɹ���" << endl;
        cout << "ҩ�ѣ�" << drug_fee << endl;
        return drug_fee;
    }
    cout<<"�������"<<endl;
    return -1;
};
string Patient::getdc_name()
{
    cout << "�û���ҽ��������";
    cin >> dc_name;
    if (dc_name == " ")
    {
        cout << "���������룺";
        cin >> dc_name;
        if (dc_name == " ")
            cout << "�������" << endl;
        else
        {
            cout << "����ɹ���" << endl;
            cout << "ҽ��������" << dc_name << endl;
            return dc_name;
        }
    }
    else
    {
        cout << "����ɹ���" << endl;
        cout << "������" << dc_name << endl;
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
        cout << "���ļ�ʧ�ܣ�";
        return;
    }
    while(infile>>name[i]>>gender[i]>>age[i]>>number[i]>>address[i]>>doctor_name[i]>>office_visit_fee[i]>>drug_fee[i])
    {
        cout << "����������" << name[i] << endl;
        cout << "�Ա�"<< gender[i] << endl;
        cout << "���䣺" << age[i] << endl;
        cout << "�绰���룺" << number[i] << endl;
        cout << "��ַ��" << address[i] << endl;
        cout << "ҽ��������" << doctor_name[i] << endl;
        cout << "��ѣ�" << office_visit_fee[i] << endl;
        cout << "ҩ�ѣ�" << drug_fee[i] << endl;
        cout << "�ܷ��ã�" << office_visit_fee[i] + drug_fee[i] << endl;
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
        cout << "��bill.txt�ļ�ʧ�ܣ�" << endl;
        return;
    }
    doctor_name = Doctor_name;
    outfile << doctor_name << " ";
    outfile.close(); // �ر��ļ�
}
void Bill::save_patient_name(string Patient_name)
{
    ofstream outfile(bill_txt_path, ios::out | ios::app);
    if (!outfile)
    {
        cout << "��bill.txt�ļ�ʧ�ܣ�" << endl;
        return;
    }
    patient_name = Patient_name;
    outfile << patient_name << " ";
    outfile.close(); // �ر��ļ�
}
void Bill::save_office_visit_fee(double Office_visit_fee)
{
    ofstream outfile(bill_txt_path, ios::out | ios::app);
    if (!outfile)
    {
        cout << "��bill.txt�ļ�ʧ�ܣ�" << endl;
        return;
    }
    office_visit_fee = Office_visit_fee;
    outfile << office_visit_fee << " ";
    outfile.close(); // �ر��ļ�
}
void Bill::save_drug_fee(double Drug_fee)
{
    ofstream outfile(bill_txt_path, ios::out | ios::app);
    if (!outfile)
    {
        cout << "��bill.txt�ļ�ʧ�ܣ�" << endl;
        return;
    }
    drug_fee = Drug_fee;
    outfile << drug_fee << " ";
    outfile.close(); // �ر��ļ�
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
        cout << "���ļ�ʧ�ܣ�";
        return;
    }
    while(infile>>patient_name[i]>>doctor_name[i]>>office_visit_fee[i]>>drug_fee[i])
    {
        cout << "����������" << patient_name[i] << endl;
        cout << "ҽ��������" << doctor_name[i] << endl;
        cout << "��ѣ�" << office_visit_fee[i] << endl;
        cout << "ҩ�ѣ�" << drug_fee[i] << endl;
        cout << "�ܷ��ã�" << office_visit_fee[i]+drug_fee[i]<< endl<<endl;
        i++;
    }
    cout<<"���л��ߺϼƷ��ã�"<<sum<<endl;
}

Doctor doctor;
Patient patient;
Bill bill;

void input_1()
{
    int num,i;
    {
        cout << "������Ҫ���ҽ����Ϣ��������";
        cin >> num;
        ofstream outfile(doctor_txt_path, ios::out | ios::app);
        if (!outfile)
            cout << "���ļ�ʧ�ܣ�" << endl;
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
            outfile.close(); // �ر��ļ�
        }
    }
}
void input_2()
{
    int num,i,t;
    string T;
    cout << "��������Ҫ��ӻ�����Ϣ��������";
    cin >> num;
    ofstream outfile(patient_txt_path, ios::out | ios::app);
    if (!outfile)
        cout << "���ļ�ʧ�ܣ�" << endl;
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
        outfile.close(); // �ر��ļ�
    }
}
int getMenuChoice()
{
    int choice;
    cout << "������ѡ���ţ�";
    cin >> choice;
    while (getchar() != '\n')
        ; // ������뻺����
    return choice;
}
// �˵�
void menu()
{
    system("cls");      // ����
    system("color 74"); // ������ɫ
    printf("\n");
    cout << "\t\t\t\t************************************************\n";
    cout << "\t\t\t\t*              ������Ϣ����ϵͳ                *\n";
    cout << "\t\t\t\t************************************************\n";
    cout << "\t\t\t\t*                                              *\n";
    cout << "\t\t\t\t*              1. ¼����Ϣ                      *\n";
    cout << "\t\t\t\t*              2. ��ѯ��Ϣ                      *\n";
    cout << "\t\t\t\t*              3. �޸���Ϣ                      *\n";
    cout << "\t\t\t\t*              4. ����˵�                      *\n";
    cout << "\t\t\t\t*              0. �˳�ϵͳ                      *\n";
}
void menu_search()
{
    cout << "\t\t\t\t************************************************\n";
    cout << "\t\t\t\t*                                              *\n";
    cout << "\t\t\t\t*              1.ҽ����¼                       *\n";
    cout << "\t\t\t\t*              2.���߼�¼                       *\n";
    cout << "\t\t\t\t*              3.�˵���¼                       *\n";
}
void menu_input()
{
    cout << "\t\t\t\t************************************************\n";
    cout << "\t\t\t\t*                                              *\n";
    cout << "\t\t\t\t*              1.¼��ҽ����Ϣ                    *\n";
    cout << "\t\t\t\t*              2.¼�뻼����Ϣ                    *\n";
}
// ¼����Ϣ
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
            cout << "����������������롣" << endl;
            fflush(stdin); // ������뻺����������������������
            break;
    }
}
// ��ѯ��Ϣ
void search()
{
    ifstream infile(doctor_txt_path, ios::in); // ���ļ�
    if (!infile)/* condition */
    {
        cout << "���ļ�ʧ�ܣ�" << endl;
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
// �޸���Ϣ
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
            cout << "����������������롣" << endl;
            fflush(stdin); // ������뻺����������������������
            break;
        }
        system("pause");
    } while (1);
    return 0;
}
