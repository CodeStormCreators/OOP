/*Imagine a publishing company which does marketing for book and audio cassette versions. Create a class publication that stores the title (a string) and price (type float) of publications. From this class derive two classes: book which adds a page count (type int) and tape which adds a playing time in minutes (type float).

Write a program that instantiates the book and tape class, allows user to enter data and

displays the data members. If an exception is caught, replace all the data member values with

zero values.*/


#include <iostream>
using namespace std;
class publication
{
    string title;
    float price;

public:
    void add()
    {
        cout << "Enter title : ";
        cin >> title;
        cout << "Enter price : ";
        cin >> price;
        if (price < 0)
        {
            cout << "invalid " << endl;
            price = 0;
        }
    }
    void display()
    {
        cout<<endl;
        cout << "title : " << title << endl;
        cout << "price : " << price << endl;
    }
};
class book : public publication
{
    int p_count;

public:
    void add_book()
    {
        add();
        cout << "Enter page count for book : ";
        cin >> p_count;
        if (p_count < 0)
        {
            cout << "Invalid count..." << endl;
            p_count = 0;
        }
    }
    void dis_book()
    {
        display();
        cout << "Page count : " << p_count << endl;
    }
};
class tape : public publication
{
    float time;

public:
    void add_tape()
    {
        add();
        cout << "Enter time count for tape : ";
        cin >> time;
        if (time < 0)
        {
            cout << "Invalid time..." << endl;
            time = 0;
        }
    }
    void dis_tape()
    {
        display();
        cout << "Time count : " << time << endl;
    }
};
int main()
{
    cout << "....BOOK...." << endl;
    book b;
    b.add_book();
    b.dis_book();
    cout << "\n....TAPE...." << endl;
    tape t;
    t.add_tape();
    t.dis_tape();
}
