#include<iostream>
#include<string>
using namespace std;

//function
char viet_thuong(char kt);
char viet_hoa(char kt);
void nhap();
bool lachuhoa(char kt);
bool lachuthuong(char kt);
bool laspace(char kt);
string chuanhoa(string st);
int main();
//variables
int T;
string arr[10001];
char viet_thuong(char kt)
{
    return kt+'a'-'A';
}
char viet_hoa(char kt)
{
    return kt+'A'-'a';
}
void nhap()
{
    cin>>T;
    cin.ignore();
    for(int i=1;i<=T;i++)
        getline(cin,arr[i]);
}
bool lachuhoa(char kt)
{
    if('A'<=kt&&kt<='Z')
        return true;
    return false;
}
bool lachuthuong(char kt)
{
    if('a'<=kt&&kt<='z')
        return true;
    return false;
}
bool lachu(char kt)
{
    if(lachuthuong(kt)||lachuhoa(kt))
        return true;
    return false;
}
string chuanhoa(string st)
{
    string ans="";
    st=" "+st;
    for (int j=0;j<st.size();j++)
        {
            if(!lachu(st[j-1])&&lachuthuong(st[j]))
                {
                    st[j]=viet_hoa(st[j]);
                    ans+=st[j];
                }
            else if(lachu(st[j-1])&&lachuhoa(st[j]))
                    {
                        st[j]=viet_thuong(st[j]);
                        ans+=st[j];
                    }
            else
                ans+=st[j];
        }
    ans.erase(0,1);
    return ans;
}
int main()
{
    nhap();
    for(int i=1;i<=T;i++)
        cout << chuanhoa(arr[i]) << endl;
    return 0;
}
