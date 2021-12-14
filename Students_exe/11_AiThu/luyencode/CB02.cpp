#include<iostream>

using namespace std;

int a,b;

void nhap()
{
    cin >>a >>b;
}

int tong(int x,int y)
{
    int s=0;
    s=x+y;
    return s;
}

int main()
{
    nhap();
    cout <<tong(a,b);
    return 0;
}
