/* Develop a program in C++ to create a database of student's information system containing the following information: Name,
Roll number, Class, Division, Date of Birth, Blood group, Contact address, Telephone number, Driving license no. and other. 
Construct the database with suitable member functions. Make use of constructor, default constructor, copy constructor, destructor, static member functions, 
friend class, this pointer, inline code and dynamic memory allocation operators-new and delete as well as exception handling. */



#include <iostream>
using namespace std;
class student
{
    friend class info;
    string name, dob, *bg, cls, add;
    int roll;
    char *div;
    long *tel, *driv;
    static int count;

public:
    student()
    {
        name = "";
        cls = "";
        dob = "dd/mm/yyyy";
        roll = 0;
        bg = new string[5];
        div = new char;
    }
    ~student()
    {
        delete div;
        delete[] bg;
    }
    student(student &o1)
    {
        this->name = o1.name;
        this->roll = o1.roll;
        this->cls = o1.cls;
        this->div = o1.div;
        this->dob = o1.dob;
        this->bg = o1.bg;
    }
    inline static void getcount()
    {
        count++;
    }
    inline static int showcount()
    {
        return count;
    }
    void getdata();
    void display();
};
int student::count = 0;
inline void student::getdata()
{
    cout << "Enter class : ";
    cin >> cls;
    cout << "Enter name : ";
    cin >> name;
    cout << "Enter DOB : ";
    cin >> dob;
    cout << "Enter division : ";
    cin >> *div;
    cout << "Enter BG : ";
    cin >> *bg;
    cout << "Enter roll : ";
    cin >> roll;
}
inline void student::display()
{
    cout<<endl;
    cout << "Name : " << name << endl;
    cout << "Cls : " << cls << endl;
    cout << "Div : " << *div << endl;
    cout << "Roll : " << roll << endl;
    cout << "BG : " << *bg << endl;
    cout << "DOB : " << dob << endl;
}
class info : public student
{
public:
    info()
    {
        add = "";
        tel = new long;
        driv = new long;
    }
    ~info()
    {
        delete tel;
        delete driv;
    }
    info(info &o2)
    {
        this->add = o2.add;
        this->tel = o2.tel;
        this->driv = o2.driv;
    }
    void getinfo();
    void display();
};
inline void info::getinfo()
{
    cout << "Enter add : ";
    cin >> add;
    cout << "Enter driv : ";
    cin >> *driv;
    long no;
    int total = 0, flag = 0;
    while (flag != 1)
    {
        cout << "Enter tel : ";
        cin >> *tel;
        no = *tel;
        while (no > 0)
        {
            total++;
            no = no / 10;
        }
        cout << "Total digits in telNo : " << total << endl;
        try
        {
            if (total == 10)
            {
                cout << "Correct number..." << endl;
                flag = 1;
            }
            else
            {
                throw(*tel);
            }
        }
        catch (long n)
        {
            cout << "Incorrect number... " << n << endl;
        }
    }
}
inline void info::display()
{
    cout << "Add : " << add << endl;
    cout << "Tel : " << *tel << endl;
    cout << "Driv : " << *driv << endl;
}
int main()
{
    student *o1[20];
    info *o2[20];
    int m = 1, n = 0;
    char ch;
    do
    {
        cout << m << " Emplyee : " << endl;
        o1[n] = new student;
        o2[n] = new info;
        o1[n]->getdata();
        o2[n]->getinfo();
        o1[n]->getcount();
        o1[n]->display();
        o2[n]->display();
        m++;
        cout << "Do you want to add more (y/n) : ";
        cin >> ch;
    } while (ch == 'y');

    int a;
    a = o1[n]->showcount();
    cout << "\nTotal no. of employee : " << a << endl;
    return 0;
}
