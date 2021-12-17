#include<iostream>
#include<math.h>

using namespace std;

int t,arr[10000];

void nhap()
{
    cin >>t;
    for (int i=1;i<=t;i++)
        cin >>arr[i];
}

bool rutcanduoc(int k)
{
    float x;
    x=cbrt(k);
    if (x==(int)x)
        return true;
    else
        return false;
}

int main()
{
    nhap();
    for (int i=1;i<=t;i++)
    {
        if (!rutcanduoc())
            cout << "NO";
        else
            cout << "YES";
    }
    return 0;
}
