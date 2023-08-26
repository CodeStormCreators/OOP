/* Write a program in C++ to use map associative container. The keys will be the names of states and the values will be the populations of the states.
When the program runs, the user is prompted to type the name of a state. The program then looks in the map, using the state name as an index and
returns the population of the state.*/


#include <iostream>
#include <map>
using namespace std;

class info
{
    map<string, int> amap;
    string state;
    int population;

public:
    void add()
    {
        cout << "Enter the state : ";
        cin >> state;
        cout << "Enter the population : ";
        cin >> population;
        amap[state] = population;
    }
    void display()
    {
        cout<<"\n.........States with their populations..........."<<endl;
        map<string, int>::iterator it;
        for (it = amap.begin(); it != amap.end(); it++)
        {
            cout << it->first << "  " << it->second << endl;
        }
    }
    void findpopulation()
    {
        string x;
        cout << "Enter the state for finding the population :";
        cin >> x;
        if(amap.find(x)==amap.end()){
            cout<<"No such state found..."<<endl;
        }
        else{
            cout << x << "  " << amap.find(x)->second << endl;
        }
    }
};
int main()
{
    info obj;
    int n;
    cout << "No. of informations ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        obj.add();
    }
    obj.display();
    obj.findpopulation();
}
