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
        for (int j=1;j<=n;j++)
        {
            cout << "2";
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

