#include<iostream>
#include<iomanip>

using namespace std;

float r,pi=3.14;

void nhap()
{
    cin >>r;
}

float tinhcv(int x)
{
    float cv=2*x*pi;
    return cv;
}

float tinhdt(int x)
{
    float dt=(float)x*x*pi;
    return dt;
}

int main()
{
    nhap();
    cout <<fixed;
    cout.precision(3);
    cout <<tinhcv(r) <<endl;
    cout <<tinhdt(r);
    return 0;
}
