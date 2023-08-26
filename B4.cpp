/*Write a C++ program that creates an output file, writes information to it, closes the file, open it again as an input file and 
read the information from the file.*/


#include <iostream>
#include <fstream>
using namespace std;
class file
{
    char text;

public:
    void write()
    {
        //Enter * at the end of entered string for terminating it.....
        ofstream o1;
        o1.open("data.txt",ios::out);
        cin.get(text);
        while (text != '*')
        {
            o1.put(text);
            cin.get(text);
        }
        o1.close();
    }
    void read()
    {
        ifstream o2;
        o2.open("data.txt",ios::in);
        text=o2.get();
        while(!o2.eof()){
            cout<<text;
            text=o2.get();
        }
        o2.close();
    }
};
int main()
{
    file o;
    o.write();
    o.read();
}
