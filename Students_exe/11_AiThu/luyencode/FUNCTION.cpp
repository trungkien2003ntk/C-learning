#include<iostream>

using namespace std;

long a,b,c,x;

void nhap()
{
    cin >>a >>b >>c >>x;
}

int tinhtoan(long A,long B,long C,long X)
{
    long long s=A*X*X+B*X+C;
    return s;
}

int main()
{
    nhap();
    cout <<tinhtoan(a,b,c,x);
    return 0;
}
