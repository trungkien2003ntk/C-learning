#include<iostream>
#include<string>

using namespace std;

int T,res[101],tong,cs=0;
string st;
char arr[101];

void nhap()
{
    getline(cin,st);
    cin >>T;
    for (int i=1;i<=T;i++)
    {
        cin >>arr[i];
    }
}

void dem()
{
    for (int i=1;i<=T;i++)
    {
        tong=0;
        for (int j=0;j<st.size();j++)
        {
            if (st[j]==arr[i]||st[j]==arr[i]+'A'-'a'||st[j]+'A'-'a'==arr[i])
                tong++;
        }
        cs++;
        res[cs]=tong;
    }
    for (int i=1;i<=T;i++)
    {
        cout <<res[i] <<endl;
    }
}

int main()
{
    nhap();
    dem();
    return 0;
}
