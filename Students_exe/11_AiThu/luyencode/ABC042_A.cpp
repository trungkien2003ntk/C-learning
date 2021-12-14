#include<iostream>

using namespace std;

int a,b,c;

void nhap()
{
    cin >>a >>b >>c;
}

void check()
{
    int s=0;
    s=a+b+c;
    if (s==17)
    {
        if ((a==5&&b==5&&c==7)||(a==5&&b==7&&c==5)||(a==7&&b==5&&c==5))
            cout << "YES";
        else
            cout << "NO";
    }
    else
        cout << "NO";
}

int main()
{
    nhap();
    check();
    return 0;
}
