#include<iostream>
using namespace std;
int n,a,b;
void nhap()
{
    cin>>n;
    cin>>a>>b;
}
void check(int n,int a,int b)
{
    if (n%a==0 || n%b==0)
    {
        if(n%a==0 && n%b!=0)
            cout << "Chi chia het cho "<<a<<".";
        else
        {
            if (n%b==0 && n%a!=0)
                cout << "Chi chia het cho "<<b<<".";
            else
                cout << "Co, tat ca!";
        }
    }
    else
        cout << "Khong chia het cho so nao ca.";
}
int main()
{
    nhap();
    check(n,a,b);
    return 0;
}

