#include<iostream>
#include<string>

using namespace std;

string str;

void nhap()
{
    getline(cin,str);
}

char viet_thuong(char kt)
{
    return kt+'a'-'A';
}

bool la_chu(char kt)
{
    if (la_chu_hoa(kt)||la_chu_thuong(kt))
        return true;
    return false;
}

bool la_chu_hoa(char kt)
{
    if ('A'<=kt&&kt<='Z')
        return true;
    return false;
}

bool la_so(char kt)
{
    if ('0'<=kt&&kt<='9')
        return true;
    return false;
}

bool la_chu_thuong(char kt)
{
    if ('a'<=kt&&kt<='z')
        return true;
    return false;
}

string chuoi_moi(string st)
{
    string chuoimoi="";
    for (int i=0;i<st.size();i++)
    {
        if (la_chu(st[i])&&la_chu_hoa(st[i]))
        {
            st[i]=viet_thuong(st[i]);
            chuoimoi+=st[i];
        }
        else if (la_chu(st[i])&&la_chu_thuong(st[i]))
            chuoimoi+=st[i];
    }
    return chuoimoi;
}

void dem()
{
    string stnew=chuoi_moi(str);
    int tong,ans[10],kitu[30];
    for (int i=0;i<stnew.size();i++)
    {
        tong=0;
        for (int k=0;k<=cs;k++)
            for (int j=0;j<stnew.size();j++)
            {
                if (stnew[i]==stnew[j])
                {
                    tong++;
                    stnew=erase(stnew[j],1);
                }
            }
            if (tong!=0)
            {
                cs++;
                ans[cs]=tong;
                kitu[k]=stnew[i];
            }
    }
    for (int i=1;i<=cs;i++)
    {
        for (int j=1;j<=cs;j++)
    }
}

int main()
{
    nhap();
    dem();
    return 0;
}
