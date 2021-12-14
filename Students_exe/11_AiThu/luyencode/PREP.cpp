#include<iostream>

using namespace std;

int A,B,X,Y;

void nhap()
{
    cin >>A >>B >>X >>Y;
}

int tinhtien(int a,int b,int x,int y)
{
    int s=a*x+b*y;
    return s;
}

int main()
{
    nhap();
    cout <<tinhtien(A,B,X,Y);
    return 0;
}

