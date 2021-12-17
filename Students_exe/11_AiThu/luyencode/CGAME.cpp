#include<iostream>

using namespace std;

unsigned long a,b;

void nhap()
{
    cin >>a >>b;
}

bool kiemtra(unsigned long x,unsigned long y)
{
    bool kq;
    if (x>y)
        return true;
    else
        return false;
    return kq;
}

int main()
{
    nhap();
    if (!kiemtra(a,b))
        cout << "0";
    else
        cout << "1";
    return 0;
}
