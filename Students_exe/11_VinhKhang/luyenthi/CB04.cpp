#include <iostream>
#include<iomanip>
using namespace std;
int a,b;
void nhap()
{
    cin>>a>>b;
}
int tong(int x,int y)
{
    int kq;
    kq=a+b;
    return kq;
}
int hieu(int x,int y)
{
    int kq;
    kq=a-b;
    return kq;
}
int tich(int x,int y)
{
    int kq;
    kq=a*b;
    return kq;
}
float thuong(int x,int y)
{
    float kq;
    kq=(float)x/y;
    return kq;
}
int main()
{
    nhap();
    cout<<tong(a,b) << endl;
    cout<<hieu(a,b) << endl;
    cout<<tich(a,b) << endl;
    if(b==0)
        cout << "INF";
    else
        {
            cout <<fixed;
            cout.precision(2);
            cout << thuong(a,b);
        }
    return 0;
}
