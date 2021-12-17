#include<iostream>
using namespace std;
int n;
void nhap()
{
    cin>>n;
}
void xuli(int x)
{
    int kq=x;
    int s=0;
    while(kq!=0)
    {
        s+=kq%10;
        kq/=10;
    }
    if(s%10==9)
        cout << "YES";
    else
        cout << "NO";
}

int main()
{
    nhap();
    xuli(n);
    return 0;
}
