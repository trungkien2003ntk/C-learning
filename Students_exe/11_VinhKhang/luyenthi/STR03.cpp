#include<iostream>
#include<string>
using namespace std;
int T,tong;
int cs=0,kq[101];
char arr[101];
string str,st;
void nhap()
{
    getline(cin,str);
    cin>> T;
    for(int i=1;i<=T;i++)
    {
        cin >> arr[i];
    }
}

bool la_chu( char x)
{
    bool kq=false;
    if(('a'<=x && x<='z') ||('A'<=x && x<='Z'))
        kq=true;
    return kq;
}

bool kieuchu(char x,char y)
{
    bool kq=false;
    if(x==y || x==y+'A'-'a'|| x==y+'a'-'A')
        kq=true;
    return kq;
}
void demkt()
{
    for(int i=1;i<=T;i++)
    {
        tong=0;
        for(int j=0;j<=str.size();j++)
        {
            //if(('a'<=str[j] && str[j]<='z') ||('A'<=str[j] && str[j]<='Z'))
            if(la_chu(str[j]))
                //if(str[j]==arr[i] || str[j]==arr[i]+'A'-'a'|| str[j]==arr[i]+'a'-'A')
                if(kieuchu(str[j],arr[i]))
                    tong++;
        }
        cs++;
        kq[cs]=tong;
    }
    for(int i=1;i<=T;i++)
        cout << kq[i] << endl;
}

int main()
{
    nhap();
    demkt();
    return 0;
}
