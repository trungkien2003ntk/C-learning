#include<iostream>
#include<string>
//khai bao tat ca cac thu vien
//#include<bits/stdc++.h>
using namespace std;
string s;
int m,L,R;
int tong,cs=0;
string kq[5001],dacat;
string ans="";
void nhap()
{
    cin>>s;
    cin>>m;
}
string catchuoi(string st,int a,int b)
{
    string chuoi;
    chuoi=st.substr(a-1,b-a+1);
    return chuoi;
}
bool xetdoixung(string st)
{
    string st1="";
    for(int i=st.size()-1;i>=0;i--)
        st1+=st[i];
    if (st1==st)
        return true;
    return false;
}
void xuli()
{
    for (int i=1;i<=m;i++)
    {
        cin>>L>>R;
        dacat=catchuoi(s,L,R);
        if(xetdoixung(dacat)){
            ans="YES";
            cs++;
            kq[cs]=ans;

        }
        else{
            ans="NO";
            cs++;
            kq[cs]=ans;
        }
    }
    for(int i=1;i<=m;i++){
        cout << kq[i] << endl;
    }
}
int main()
{
    nhap();
    xuli();
    return 0;
}
