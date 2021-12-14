#include<iostream>

using namespace std;

int n;

void nhap()
{
    cin >>n;
}

void xuat()
{
    for (int i=0;i<=n;i++)
    {
        for (int j=1;j<=i;j++)
        {
            cout << "!";
        }
        for (int k=1;k<=n;k++)
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
