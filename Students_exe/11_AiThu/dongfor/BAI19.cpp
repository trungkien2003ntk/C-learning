#include<iostream>

using namespace std;

int n;

void nhap()
{
    cin >>n;
}

void xuat()
{
    for (int i=n;i>=1;i--)
    {
        for (int j=i;j>=1;j--)
        {
            cout <<i;
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

