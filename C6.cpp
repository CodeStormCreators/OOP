/*Write C++ program using STL for sorting and searching user defined records such as personal records (Name, DOB, Telephone number etc) using vector container.*/




#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class stl
{
public:
    string name, dob;
    long tel;
    void add()
    {
        cout<<endl;
        cout << "Enter your Name : ";
        cin >> name;
        cout << "Enter your DOB : ";
        cin >> dob;
        cout << "Enter your TeliphoneNo : ";
        cin >> tel;
    }
    void display()
    {
        cout << name << "\t\t" << dob << "\t\t" << tel << endl;
    }
};
int main()
{
    int n, ch;
    char ch1;
    string key;
    cout << "No. of data you want to add ";
    cin >> n;
    vector<stl> v(n);
    vector<string> name(n);
    do
    {
        cout << "\n 1)Addition of data\n 2)Sorting of data\n 3)Searching of data\n"
             << endl;
        cout << "Enter your choice ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                v[i].add();
            }
            break;
        case 2:
            for (int i = 0; i < n; i++)
            {
                name[i] = v[i].name;
            }
            sort(name.begin(), name.end());
            cout << "...Sorted data..." << endl;
            cout << "Name\t\tDOB\t\tTeliphone-No" << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (name[i] == v[j].name)
                    {
                        v[j].display();
                        break;
                    }
                }
            }
            break;
        case 3:
            for (int i = 0; i < n; i++)
            {
                name[i] = v[i].name;
            }
            sort(name.begin(), name.end());
            cout << "Enter the name that you want to search ";
            cin >> key;
            if (binary_search(name.begin(), name.end(), key))
            {
                cout << "Record found..." << endl;
            }
            else
            {
                cout << "Record not found..."<<endl;
            }
            break;
        default:
            break;
        }
        cout << "Do you want to continue other oprations (y/n) : ";
        cin >> ch1;
    } while (ch1 == 'y');
}
