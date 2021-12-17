#include<iostream>
using namespace std;
int d,m,y;

void nhap()
{
    cin>>d>>m>>y;
}
void xuli(int a,int b,int c)
{
    cout << "users setClock\\";
    cout << b << "\\" << a << "\\" << c;
}
int main()
{
    nhap();
    xuli(d,m,y);
    return 0;
}
