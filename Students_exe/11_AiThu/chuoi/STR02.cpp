#include<iostream>
#include<string>

using namespace std;

int T;
string str,arr[10001];

void nhap();
bool lachuthuong(char kt);
bool lachuhoa(char kt);
bool lachu(char kt);
char viethoa(char kt);
char vietthuong(char kt);
bool laspace(char kt);
string thanhstr(char kt);
string chuanhoa(string st);
void xuly();

void nhap()
{
    cin >>T;
    cin.ignore();
    for (int i=1;i<=T;i++)
        getline(cin,arr[i]);
}

bool lachuthuong(char kt)
{
    if ('a'<=kt&&kt<='z')
        return true;
    return false;
}

bool lachuhoa(char kt)
{
    if ('A'<=kt&&kt<='Z')
        return true;
    return false;
}

bool lachu(char kt)
{
    if (lachuhoa(kt)||lachuthuong(kt))
        return true;
    return false;
}

char viethoa(char kt)
{
    return kt+'A'-'a';
}

char vietthuong(char kt)
{
    return kt+'a'-'A';
}

bool laspace(char kt)
{
    if (kt==' ')
        return true;
    return false;
}

string thanhstr(char kt)
{
    string strr(1,kt);
    return strr;
}

string chuanhoa(string st)
{
    st=" "+st;
    string chuhoastr,chuthuongstr,ans="";
    for (int j=0;j<st.size();j++)
    {
        if (!lachu(st[j-1]) && lachuthuong(st[j]))
        {
            st[j]=viethoa(st[j]);
            ans+=st[j];
        }
        else if (lachu(st[j-1]) && lachuhoa(st[j]))
        {
            st[j]=vietthuong(st[j]);
            ans+=st[j];
        }
        else
            ans+=st[j];
    }
    ans=ans.erase(0,1);
    return ans;
}

int main()
{
    nhap();
    for (int i=1;i<=T;i++)
    {
        cout<<chuanhoa(arr[i])<<endl;
    }
    return 0;
}
