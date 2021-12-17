#include<iostream>

using namespace std;

int n;

void nhap()
{
    cin >>n;
}

int tongcacchuso(int x)
{
    int sodu;
    int k=0;
    while (x!=0)
    {
        sodu=x%10;
        k+=sodu;
        x=x/10;
    }
    return k;
}

bool sosanh(int y)
{
    bool kq;
    int k=tongcacchuso(y)%10;
    if (k==9)
        kq=true;
    else
        kq=false;
    return kq;
}

int main()
{
    nhap();
    if (sosanh(n))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
