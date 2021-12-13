#include<iostream>
using namespace std;
int a;
void nhap()
{
    cin>>a;
}
int gapdoi(int x)
{
    int kq;
    kq=x*2;
    return kq;
}
int main()
{
    nhap();
    cout << gapdoi(a);
    return 0;
}
