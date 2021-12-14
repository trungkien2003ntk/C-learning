#include<iostream>

using namespace std;

int a,b,c;

void nhap()
{
    cin >>a >>b >>c;
}

int tinh(int x,int y,int z)
{
    int s=(x-y)*z;
    return s;
}
 int main()
 {
     nhap();
     cout <<tinh(a,b,c);
     return 0;
 }
