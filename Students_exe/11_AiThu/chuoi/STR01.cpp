#include<iostream>
#include<string>

using namespace std;
string str;

void nhap()
{
    getline(cin,str);
}

void xuly()
{
    char strr;
    for (int i=0;i<str.size();i++)
    {
        if ('A'<=str[i]&&str[i]<='Z')
        {
            strr=str[i]+'a'-'A';
            cout <<strr;
        }
        else
            cout <<str[i];
    }
}

int main()
{
    nhap();
    xuly();
    return 0;
}
