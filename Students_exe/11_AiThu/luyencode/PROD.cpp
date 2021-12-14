#include<iostream>

using namespace std;

int a,b,t;

void nhap()
{
    cin >>a >>b;
}

int tinhtich(int x,int y)
{
    t=x*y;
    return t;
}

void xuat()
{
    if (t<0)
        cout << "-1";
    else
        if (t>0)
            cout << "1";
                else
                    cout << "0";
}

int main()
{
    nhap();
    cout <<tinhtich(a,b) <<endl;
    xuat();
    return 0;
}


