#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main()
{
    float a,b,c;
    double delta;
    float x1,x2;
    cout << "Giai phuong trinh bac 2 ax^2+bx+c=0"<<endl;
    cout << "Nhap so thuc a: ";
    cin >> a;
    cout << "Nhap so thuc b: ";
    cin >> b;
    cout << "Nhap so thuc c: ";
    cin >> c;
    //Cau truc lenh giai phuong trinh
    if (a!=0)
        {
            delta = pow(b,2)-4*a*c;
            if (delta>0)
                {
                    x1 = (-b+sqrt(delta))/(2*a);
                    x2 = (-b-sqrt(delta))/(2*a);
                    cout << "Phuong trinh co hai nghiem phan biet: " << endl;
                    cout << "x_1= " << setw(5) << x1 << "; x_2= "<< setw(5) << x2;
                }
            if (delta=0)
                cout << "Phuong trinh co nghiem kep: x= " << setw(5) << -b/(2*a);
            if (delta<0)
                cout << "Phuong trinh vo nghiem.";
        }
    else
        {
            x1= -c/b;
            cout << "Phuong trinh la phuong trinh bac nhat. "<< endl;
            cout << "Phuong trinh co nghiem x= " << setw(5) << x1; 
        }
    return 0;
}