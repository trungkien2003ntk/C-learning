#include<iostream>

using namespace std;

unsigned long a,b;

void nhap()
{
    cin >>a >>b;
}

int timsodu(int x,int y)
{
    int sodu=x%y;
    return sodu;
}

int main()
{
    nhap();
    cout <<timsodu(a,b);
    return 0;
}
