#include<iostream>
#include<string>
#include<math.h>

using namespace std;

string st,chuoi[1000];

void nhap()
{
    cin >>st;
}

bool prime(int n)
{
    if (n<=1)
        return 0;
    for (int i=2;i<=round(sqrt(n));i++)
    {
        if (n%i==0)
            return 0;
    }
    return 1;
}

void xuly()
{
    for (int i=0;i<st.size();i++)
    {
        if (prime(i))
            cout << "*";
        else
            cout <<st[i];
    }
}

int main()
{
    nhap();
    xuly();
    return 0;
}
