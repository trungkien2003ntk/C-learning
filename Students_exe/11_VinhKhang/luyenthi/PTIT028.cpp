#include<iostream>
using namespace std;
float x;
void nhap()
{
    cin>>x;
}
int soduong1(int n)
{
    int kq;
    kq=n;
    return kq;
}
int soduong2(int n)
{
    int kq;
    kq=n+1;
    return kq;
}
int soam1(int n)
{
    int kq;
    kq=n-1;
    return kq;
}
int soam2(int n)
{
    int kq;
    kq=n;
    return kq;
}
void xuli(int k)
{
    if(x>=0)
        cout << soduong1(k) << " " << soduong2(k);
    else
        cout << soam1(k) << " " << soam2(k);
}
int main()
{
    nhap();
    xuli(x);
    return 0;
}
