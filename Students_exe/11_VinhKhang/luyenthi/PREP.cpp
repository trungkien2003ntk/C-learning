#include<iostream>
using namespace std;
int a,b,x,y;
void nhap()
{
    cin>>a>>b>>x>>y;
}
int tinhtien(int p,int t,int v,int k)
{
    int kq;
    kq =(p*v)+(t*k);
    return kq;
}
int main()
{
    nhap();
    cout << tinhtien(a,b,x,y);
    return 0;
}
