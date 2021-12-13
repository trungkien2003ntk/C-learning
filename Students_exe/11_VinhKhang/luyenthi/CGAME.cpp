#include<iostream>
using namespace std;
int a,b;
void nhap()
{
    cin>>a>>b;
}
bool check(int x,int y)
{
    if(x>y)
        return 1;
    else
        return 0;
}
int main()
{
    nhap();
    cout << check(a,b);
    return 0;
}
