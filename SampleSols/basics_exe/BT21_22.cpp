//Chuong trinh tinh tong va tich tat ca cac uoc so cua n 
#include <iostream>

using namespace std;
int main()
{
    int i,n;
    long s=0;
    long p=1;
    cout << "Nhap n: ";
    cin >> n;
    for (i=1;i<=n;i++)
        if (n%i==0)
            {
                s+=i;
                p*=i;
            }
    cout << "Tong cac uoc so cua " << n << " la: " << s << endl;
    cout << "Tich cac uoc so cua " << n << " la: " << p << endl;
    return 0;
}