#include<iostream>
#include<string>

using namespace std;
//function
void nhap();
bool lachuhoa(char kt);
bool lachuthuong(char kt);
bool laso(char kt);
bool lachu(char kt);
char viet_thuong(char kt);
bool demduoc(char kt);
void xuli();
int main();
//variables
string s;
int dem[10+'z'-'a'+2];
int cs=0;
void nhap()
{
    getline(cin,s);
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
bool laso(char kt)
{
    if('0'<=kt&&kt<='9')
        return true;
    return false;
}
bool lachu(char kt)
{
    if(lachuhoa(kt)||lachuthuong(kt))
        return true;
    return false;
}
char viet_thuong(char kt)
{
    return kt+'a'-'A';
}
bool demduoc(char kt)
{
    if(lachu(kt)&&laso(kt))
        return true;
    return false;
}
void xuli()
{
    fill_n(dem,10+'z'-'a'+2,0);

    for(int i=0;i<s.size();i++){
        if(lachuhoa(s[i]))
            s[i]+='a'-'A';
    }
    for(int i=0;i<s.size();i++){
        if(lachu(s[i]))
            dem[s[i]-86]++;
        else if(laso(s[i]))
                dem[s[i]-47]++;
    }

    for(int i=1;i<=10+'z'-'a'+1;i++){
        if(dem[i]!=0)
            if(i<11)
                cout << (char)(i+47)<< " " << dem[i] << endl;
            else
                cout << (char)(i+86)<< " " << dem[i] << endl;
    }
}
int main()
{
    nhap();
    xuli();
    return 0;
}
