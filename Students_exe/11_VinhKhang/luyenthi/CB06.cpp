#include <iostream>
using namespace std;
int d,r;
void nhap()
{
    cin>>d>>r;
}
int s(int a,int b)
{
    int kq;
    kq=a*b;
    return kq;
}
int c(int a,int b)
{
    int kq;
    kq=(a+b)*2;
    return kq;
}
int main()
{
    nhap();
    cout << c(d,r) << endl;
    cout << s(d,r);
    return 0;
}
