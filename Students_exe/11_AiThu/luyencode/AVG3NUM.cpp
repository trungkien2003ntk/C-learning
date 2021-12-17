#include<iostream>

using namespace std;

int a,b,x;

void nhap()
{
    cin >>a >>b >>x;
}

int xuly(int A,int B,int X)
{
    int c=3*X-A-B;
    return c;
}

int main()
{
    nhap();
    cout <<xuly(a,b,x);
    return 0;
}
