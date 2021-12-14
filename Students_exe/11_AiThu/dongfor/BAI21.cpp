#include<iostream>

using namespace std;

int n;

void nhap()
{
    cin >>n;
}

void xuat()
{
    int k=0;
    for (int i=1;i<=n;i++)
    {
        k++;
        cout <<k;
        if (i==k)
            cout <<endl;;
    }
}

int main()
{
    nhap();
    xuat();
    return 0;
}
