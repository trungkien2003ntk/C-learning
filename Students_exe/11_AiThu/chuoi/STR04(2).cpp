#include<iostream>
#include<string>

using namespace std;

string str;

void nhap();
char viet_thuong(char kt);
bool dem_duoc(char kt);
bool la_chu(char kt);
bool la_chu_hoa(char kt);
bool la_chu_thuong(char kt);
bool la_so(char kt);
string chuoi_moi(string st);
void dem();

void nhap()
{
    getline(cin,str);
}

char viet_thuong(char kt)
{
    return kt+'a'-'A';
}

bool dem_duoc(char kt)
{
    if (la_chu(kt)||('0'<=kt&&kt<='9'))
        return true;
    return false;
}

bool la_chu(char kt)
{
    if (('a'<=kt&&kt<='z')||('A'<=kt&&kt<='Z'))
        return true;
    return false;
}

bool la_chu_hoa(char kt)
{
    if ('A'<=kt&&kt<='Z')
        return true;
    return false;
}

bool la_chu_thuong(char kt)
{
    if ('a'<=kt&&kt<='z')
        return true;
    return false;
}

bool la_so(char kt)
{
    if ('0'<=kt&&kt<='9')
        return true;
    return false;
}

string chuoi_moi(string st)
{
    string strmoi="";
    for (int i=0;i<st.size();i++)
    {
        if (la_chu(st[i])&&la_chu_hoa(st[i]))
        {
            st[i]=viet_thuong(st[i]);
            strmoi+=st[i];
        }
        else if (la_chu(st[i])&&la_chu_thuong(st[i]))
            strmoi+=st[i];
        else
            strmoi+=st[i];
    }
    return strmoi;
}

void dem()
{
    string strnew=chuoi_moi(str);
    int demkitu[10+'z'-'a'+2];
    fill_n(demkitu,10+'z'-'a'+2,0);
    for (int i=0;i<strnew.size();i++)
    {
        if (dem_duoc(strnew[i]))
        {
            if (la_chu(strnew[i]))
                demkitu[strnew[i]-86]++;
            else if (la_so(strnew[i]))
                demkitu[strnew[i]-47]++;
        }
    }
    for (int i=1;i<=10+'z'-'a'+1;i++)
    {
        if (demkitu[i]!=0)
            if(i<=10)
                cout <<(char)(i+47) << " " <<demkitu[i] <<endl;
            else
                cout <<(char)(i+86) << " " <<demkitu[i] <<endl;
    }
}

int main()
{
    nhap();
    dem();
    return 0;
}
