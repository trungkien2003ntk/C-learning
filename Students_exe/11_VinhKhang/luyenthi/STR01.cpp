#include<iostream>
#include<string>
using namespace std;
string st;
void nhap()
{
    getline(cin,st);
}
char vietthuong(char kt)
{
    return kt+'a'-'A';
}
char viethoa(char kt)
{
    return kt+'A'-'a';
}
bool lachuhoa(char kt)
{
    bool kq=false;
    if('A'<=kt&&kt<='Z')
        kq=true;
    return kq;
}
void xuli()
{
    for(int i=0;i<=st.size();i++)
    {
        if(lachuhoa(st[i]))
            st[i]+='a'-'A';
    }
    cout << st;
}
int main()
{
   nhap();
   xuli();
   return 0;
}
