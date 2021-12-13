#include<iostream>

using namespace std;
int a,b,c;
void nhap()
{
    cin>>a>>b>>c;
}
void check(int x,int y,int z)
{
    if ((x==5&&y==7&&z==5)||(x==5&&y==5&&z==7)||(x==7&&y==5&&z==5))
        cout << "YES";
    else
        cout << "NO";
}
int main()
{
    nhap();
    check(a,b,c);
    return 0;
}
