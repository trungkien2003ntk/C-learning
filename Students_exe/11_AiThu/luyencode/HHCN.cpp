#include<iostream>
#include<math.h>

using namespace std;

unsigned long a,b,c;

void nhap()
{
    cin >>a >>b >>c;
}

int tongcanh(unsigned long x,unsigned long y,unsigned long z)
{
    unsigned long cao,dai,rong;
    unsigned long tong;
    cao=sqrt(x);
    rong=sqrt(x);
    dai=y/cao;
    tong=4*(cao+rong+dai);
    return tong;
}

int main()
{
    nhap();
    cout <<tongcanh(a,b,c);
    return 0;
}
