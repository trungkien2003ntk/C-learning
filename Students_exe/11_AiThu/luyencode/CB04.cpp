#include<iostream>
#include<iomanip>

using namespace std;

float a,b;

void nhap()
{
    cin >>a >>b;
}

int tong(int x,int y)
{
    int s;
    s=x+y;
    return s;
}

int hieu(int x,int y)
{
    int h;
    h=x-y;
    return h;
}

int tich(int x,int y)
{
    int t;
    t=x*y;
    return t;
}

float thuong(int x,int y)
{
    float th;
    th=(float)x/y;
    return th;
}

int main()
{
    nhap();
    cout <<tong(a,b) <<endl;
    cout <<hieu(a,b) <<endl;
    cout <<tich(a,b) <<endl;
    if (b!=0)
    {
        cout <<fixed;
        cout.precision(2);
        cout <<thuong(a,b);
    }
    else
        cout << "INF";
    return 0;
}

