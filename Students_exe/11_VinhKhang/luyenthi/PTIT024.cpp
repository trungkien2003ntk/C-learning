#include<iostream>
#include<cmath>
using namespace std;
string s;

void nhap()
{
    getline(cin,s);
}
bool prime(int n)
{
    if(n<=1)
        return 0;
    for(int i=2;i<=round(sqrt(n));i++)
        if(n%i==0)
            return 0;
    return 1;
}
void xuli()
{
    for(int i=0;i<s.size();i++)
    {
        if(prime(i))
            cout << "*";
        else
            cout << s[i];
    }
}
int main()
{
    nhap();
    xuli();
    return 0;
}
