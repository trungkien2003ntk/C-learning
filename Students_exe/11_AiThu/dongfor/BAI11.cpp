#include<iostream>

using namespace std;

int n;

void nhap()
{
    cin >>n;
}

void xuat()
{
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=i;j++)
        {
            cout << "*";
        }
        cout <<endl;
    }
    for (int i=n-1;i>=1;i--)
    {
        for (int k=i;k>=1;k--)
        {
            cout << "*";
        }
        cout <<endl;
    }
}

int main()
{
    nhap();
    xuat();
    return 0;
}

