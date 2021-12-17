#include<iostream>

using namespace std;

int dt,mth,yr;

void nhap()
{
    cin >>dt >>mth >>yr;
}

void xuat()
{
    // char c=92;
    cout << "users setClock " <<"\\" <<mth <<"\\"  <<dt <<"\\"  <<yr;
}

int main()
{
    nhap();
    xuat();
    return 0;
}
