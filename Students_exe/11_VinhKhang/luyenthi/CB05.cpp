#include <iostream>
using namespace std;
int a,b;
void nhap()
{
    cin>>a>>b;
}
int tinh(int x,int y)
{
    int kq;
    kq=x%y;
    return kq;
}
int main()
{
    nhap();
    cout << tinh(a,b);
    return 0;
}
