#include <iostream>
#include <string>
using namespace std;

bool chu_hoa(char x)
{
    if(x>='A'&&x<='Z')
        return 1;
    else
        return 0;
}

char viet_thuong(char x)
{
    return x=x+'a'-'A';
}

string thuong(string st)
{
    for(int x=0;x<st.length();x++)
    {
        if(chu_hoa(st[x])&&st[x]!=' ')
            st[x]=viet_thuong(st[x]);
    }
    return st;
}

void dem(int n,string st)
{
    char st_tim[1001];
    int count;
    for(int x=0;x<n;x++)
    {
        cin>>st_tim[x];
        if(chu_hoa(st_tim[x]))
           st_tim[x]=viet_thuong(st_tim[x]);
    }
    for(int i=0;i<n;i++)
    {   
        count=0;
        for(int x=0;x<st.length();x++)
        {
            if(st_tim[i]==st[x])
                count++;
        }
        cout<<count<<endl;
    }
}

int main()
{   
    string st;
    getline(cin,st);
    st=thuong(st);
    int n;
    cin>>n;
    dem(n,st);
    return 0;
}
