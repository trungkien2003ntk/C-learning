#include<iostream>

using namespace std;

int a,b,c;

void nhap()
{
    cin >>a >>b >>c;
}

int tong(int x,int y,int z)
{
    int s=0;
    s=x+y+z;
    return s;
}

int main()
{
    nhap();
    cout <<tong(a,b,c);
    return 0;
}
