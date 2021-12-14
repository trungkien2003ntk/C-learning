#include<iostream>

using namespace std;

int n,m;

void nhap()
{
    cin >>n >>m;
}

void xuat()
{
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (i==1||i==n)
                cout << "*";
            else
                if (j==1||j==m)
                    cout << "*";
                else
                    cout << " ";
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

