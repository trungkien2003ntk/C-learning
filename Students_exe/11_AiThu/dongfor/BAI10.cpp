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
        for (int j=n-i;j>=1;j--)
        {
            cout << " ";
        }
        for (int k=1;k<=i;k++)
        {
            cout << "*";
        }
        for (int m=n-i;m<n-1;m++)
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
