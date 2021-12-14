#include<iostream>

using namespace std;

long long a,b;

void nhap()
{
    cin >>a >>b;
}

int tinhs(int x,int y)
{
    int c=x+y;
    return c;
}

int main()
{
    nhap();
    cout <<a << " + " <<b << " = " <<tinhs(a,b);
    return 0;
}
