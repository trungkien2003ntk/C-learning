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
        for (int j=n-i+1;j<=n;j++)
        {
            if (i==n)
                cout << "*";
            else
                if (j==n-i+1||j==n)
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
