#include <iostream>

using namespace std;
int main()
{
    float a,b,x;
    cout << "Chuong trinh giai phuong trinh bac nhat ax+b=0" << endl;
    cout << "Nhap a: "; 
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;
    if ((a==0) && (b==0))
        cout << "Phuong trinh co vo so nghiem.";
    else
        if ((a==0) && (b!=0))
            cout << "Phuong trinh vo nghiem.";
        else
            {
                x = -b/a;
                cout << "Phuong trinh co nghiem duy nhat: x= " << x;
            }
    return 0;

}