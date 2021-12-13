#include<iostream>
using namespace std;
int n;
void nhap()
{
    cin>>n;
}
int tuoi(int k)
{
    int kq=2021;
    kq-=k;
    return kq;
}
int main()
{
    nhap();
    cout << tuoi(n);
    return 0;
}
