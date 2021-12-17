#include<iostream>
#include<cmath>
using namespace std;
int a,b,c,x;
void nhap()
{
    cin>>a>>b>>c>>x;
}
int tinh(int p,int h,int o,int k)
{
    int kq;
    kq=p*k*k+h*k+o;
    return kq;
}

int main()
{
    nhap();
    cout << tinh(a,b,c,x);
    return 0;
}
