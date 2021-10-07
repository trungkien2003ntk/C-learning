#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

int main()
{
    double a; double b; double c; double cir; double area; double p;
    cout <<"Nhap canh thu nhat: " <<  endl;
    cin >> a;
    cout <<"Nhap canh thu hai: " << endl;
    cin>> b; 
    cout <<"Nhap canh thu hai: " << endl;
    cin>> c;

    if (a+b>c && a+c>b && c+b>a)
    {
        cir = a+b+c;
        p = cir /2;
        area = sqrt(p* (p-a)* (p-b) *(p-c));
        if (a==b || a==c || b==c) //la tam giac can
        {
            if (a==b && b==c) 
                cout << "Tam giac deu" << endl;
            else 
            {
                if (a*a+b*b==c*c || a*a+c*c==b*b || c*c+b*b==a*a) 
                    cout << "Tam giac vuong can" << endl;
                else
                    cout <<"Tam giac can"<< endl;  
            }
        }
        else
        {
            if (a*a+b*b==c*c || a*a+c*c==b*b || c*c+b*b==a*a)
                cout << "Tam giac vuong" << endl;
            else 
                cout << "Tam giac thuong" << endl;

        }
    }
    else
        cout <<"Khong phai tam giac"<< endl;
    system("pause");
    return 0;
}