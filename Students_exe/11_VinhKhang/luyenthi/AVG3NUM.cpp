#include<iostream>
using namespace std;
int a,b,x;
void nhap()
{
    cin>>a>>b>>x;
}
int tinh(int k,int j,int h)
{
    int c;
    c=(h*3)-(k+j);
    return c;
}
int main()
{
    nhap();
    cout << tinh(a,b,x);
    return 0;
}
