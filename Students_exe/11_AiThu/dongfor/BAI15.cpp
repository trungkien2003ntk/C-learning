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
            if (i%2!=0)
                cout << "1";
            else
                cout << "0";
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

