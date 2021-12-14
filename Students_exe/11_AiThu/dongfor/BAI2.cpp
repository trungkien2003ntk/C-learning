#include<iostream>

using namespace std;

int n;

void nhap()
{
    cin >>n;
}

void xuat()
{
    // char c=42;
    for (int i=1;i<=n;i++)
    {
        for (int k=1;k<=i;k++)
        {
            cout <<"*";
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

