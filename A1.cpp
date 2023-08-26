/*Implement a class complex which represents the Complex Number data type, Implement the following 
1. Constructor(Including a default constuctor which creates the complex number 0+0i)
2. Overload operator + to add two complex numbers.
3. Overload operator * to multiply two complex numbers.
4. Overload operator << and >> to print and read Complex Numbers. */


#include <iostream>
using namespace std;
class complex
{
public:
    int real, imaginary;
    complex(int r = 0, int i = 0)
    {
        real = r;
        imaginary = i;
    }
    complex addcomplex(complex c1, complex c2)
    {
        complex s;
        s.real = c1.real + c2.real;
        s.imaginary = c1.imaginary + c2.imaginary;
        return s;
    }
};
int main()
{
    int x1, y1, x2, y2, x3, y3;
    cout << "1st real No. : ";
    cin >> x1;
    cout << "1st imaginary No. : ";
    cin >> y1;

    complex o1(x1, y1);
    cout << "1st complex No. " << o1.real << "+i" << o1.imaginary << "\n"
         << endl;

    cout << "2st real No. : ";
    cin >> x2;
    cout << "2st imaginary No. : ";
    cin >> y2;

    complex o2(x2, y2);
    cout << "2st complex No." << o2.real << "+i" << o2.imaginary << "\n"
         << endl;

    complex c3, c4;
    c4 = c3.addcomplex(o1, o2);
    cout << "Addition of complex no. : " << c4.real << "+i" << c4.imaginary << endl;

    x3 = (x1 * x2) - (y1 * y2);
    y3 = (x1 * y2) + (x2 * y1);
    cout << "Multiplication of complex no. : " << x3 << "+i" << y3 <<"\n"<< endl;
    return 0;
}
