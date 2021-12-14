#include<iostream>

using namespace std;

int a,b;

void nhap()
{
    cin >>a >>b;
}

int tinhr(int x,int y)
{
    int r=(x+y)*2;
    return r;
}

int tinhd(int x,int y)
{
    int d=x*y;
    return d;
}

int main()
{
    nhap();
    cout <<tinhr(a,b) <<endl;
    cout <<tinhd(a,b);
    return 0;
}
