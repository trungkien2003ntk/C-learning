#include<iostream>
using namespace std;
int a,b;
void nhap()
{
    cin>>a>>b;
}
int kt(int x,int y)
{
    if (x*y > 0)
        return 1;
    if (x*y<0)
        return -1;
    if (x*y==0)
        return 0;
}
int main()
{
    nhap();
    cout << kt(a,b);
    return 0;
}
