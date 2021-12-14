#include<iostream>

using namespace std;

int n;

void nhap()
{
    cin >>n;
}

void xuat()
{
    for (int hangdau=1;hangdau<=n;hangdau++)
    {
        cout << "*";
    }
    cout <<endl;
    for (int i=1;i<=n-2;i++)
    {
        cout << "*";
        for (int j=2;j<n;j++)
        {
            cout << " ";
        }
        cout << "*";
        cout <<endl;
    }
    for (int hangcuoi=1;hangcuoi<=n;hangcuoi++)
    {
        cout << "*";
    }
}

int main()
{
    nhap();
    xuat();
    return 0;
}
