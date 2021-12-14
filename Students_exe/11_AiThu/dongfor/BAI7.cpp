#include<iostream>

using namespace std;

int hang,cot;

void nhap()
{
    cin >>hang >>cot;
}

void xuat()
{
    for (int i=1;i<=hang;i++)
    {
        for (int j=1;j<=cot;j++)
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
