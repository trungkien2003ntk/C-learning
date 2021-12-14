#include<iostream>
#include<math.h>

using namespace std;

int n;

void nhap()
{
    cin >>n;
}

bool prime(int n)
{
    if (n<=1)
        return 0;
    for (int i=2;i<=round(sqrt(n));i++)
    {
        if (n%i==0)
            return 0;
    }
    return 1;
}
