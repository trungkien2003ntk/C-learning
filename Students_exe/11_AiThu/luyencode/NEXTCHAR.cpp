#include<iostream>

using namespace std;

char i;

void nhap()
{
    cin >>i;
}

char findktls(char k)
{
    if ('a'<=k&&k<'z')
        k=k+1;
    else
        k='a';
    return k;
}

int main()
{
    nhap();
    cout <<findktls(i);
    return 0;
}

