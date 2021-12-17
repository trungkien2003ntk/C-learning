#include<iostream>
#include<string>
using namespace std;
//function

void nhap();
void xuli();
bool lachuhoa(char kt);
bool lachuthuong(char kt);
bool lachu(char kt);
int main();
//bientoancuc
int T,cs=0;
string arr[10000];
string kq[10000];
string st;
void nhap()
{
    cin>>T;
    cin.ignore();
    for(int i=1;i<=T;i++)
        getline(cin,arr[i]);
}
void xuli()
{
    for(int k=1;k<=T;k++)
    {
        st=arr[k];
        for(int i=0;i<=st.size()-1;i++)
        {
            if(lachuhoa(st[i]))
                st[i]+='a'-'A';
        }
        for(int i=0;i<=st.size()-1;i++)
        {
            if(st[i-1]==' '||i==0)
                st[i]+='A'-'a';
        }
        cs++;
        kq[cs]=st;
    }
    for(int i=1;i<=T;i++)
        cout << kq[i] << endl;
}
bool lachuhoa(char kt)
{
    bool kq=false;
    if('A'<=kt&&kt<='Z')
        kq=true;
    return kq;
}
bool lachuthuong(char kt)
{
    bool kq=false;
    if('a'<=kt&&kt<='z')
        kq=true;
    return kq;
}
bool lachu(char kt)
{
    bool kq=false;
    if('a'<=kt&&kt<='z'||'A'<=kt&&kt<='Z')
        kq=true;
    return kq;
}
bool kitu(char kt)
{
    bool kq=false;
    if('33'<=kt&&kt<='47')
        kq=true;
    return kq;
}
int main()
{
    nhap();
    xuli();
    return 0;
}
