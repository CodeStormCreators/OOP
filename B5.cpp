/*Write a function template for selection sort that inputs, sorts and outputs an integer array and a float array.*/




#include <iostream>
#define size 10
using namespace std;
int n;

template <class T>
void sort(T s[size])
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i; j < n; j++)
        {
            if (s[j] < s[min])
            {
                min = j;
            }
        }
        T temp = s[i];
        s[i] = s[min];
        s[min] = temp;
    }
    cout << "the sorted array is : ";
    for (int k = 0; k < n; k++)
    {
        cout << s[k] << " ";
    }
    cout << endl;
}
int main()
{
    int A[size];
    float B[size];
    int ch;
    char c;
    do
    {
        cout << " 1)Integer array\n 2)Float array" << endl;
        cout << "Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "No. of integer elements : ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "Enter element ";
                cin >> A[i];
            }
            sort(A);
            break;
        case 2:
            cout << "No. of float elements : ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "Enter element ";
                cin >> B[i];
            }
            sort(B);
            break;
        default:
            cout << "Enter valid choice..." << endl;
            break;
        }
        cout << "Do you want to continue (y/n) :";
        cin >> c;
    } while (c == 'y' || c == 'Y');
}
