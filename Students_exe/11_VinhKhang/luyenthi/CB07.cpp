#include<iostream>
#include<iomanip>
using namespace std;
float r;
void nhap()
{
    cin>>r;
}
float c(float x)
{
    float kq;
    kq=x*2*3.14;
    return kq;
}
float s(float x)
{
    float kq;
    kq=x*x*3.14;
    return kq;
}
int main()
{
    nhap();
    cout << fixed;
    cout.precision(3);
    cout << c(r) << " ";
    cout << s(r);
    return 0;
}
