#include<iostream>

using namespace std;

float x;

void nhap()
{
    cin >>x;
}

int timso(float y)
{
    int a,b;
    if (y>0)
    {
        a=y;
        b=y+1;
    }
    if (y<0)
    {
        a=y-1;
        b=y;
    }
    return a;
}

int main()
{
    nhap();
    cout <<timso(x) << " " <<timso(x)+1;
    return 0;
}
