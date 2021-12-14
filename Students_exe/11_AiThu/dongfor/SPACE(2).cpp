#include<iostream>
#include<string>

using namespace std;

int T,tong,arr[101],cs=0;
string st;

void nhap()
{
    cin >>T;
}

void xuly()
{
    for (int i=1;i<=T;i++)
    {
        cin.ignore();
        getline(cin,st);
        tong=0;
        for (int j=0;j<st.size();j++)
        {
            if (st[j]==' '&&st[j]!=st[j+1])
                tong++;
        }
        cs++;
        arr[cs]=tong;
    }
    for (int i=1;i<=T;i++)
    {
        cout <<arr[i] <<endl;
    }
}

int main()
{
    nhap();
    xuly();
    return 0;
}
