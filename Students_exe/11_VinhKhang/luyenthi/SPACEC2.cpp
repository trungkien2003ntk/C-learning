#include<iostream>
#include<string>
using namespace std;
int T;
string st;
int kq[101];
int cs=0;
int tong;
void nhap()
{
    cin>>T;
}
void xuli()
{
    cin.ignore();
    for(int i=1;i<=T;i++)
    {
        getline(cin,st);
        tong=0;
        for(int j=0;j<st.size();j++)
        {
            if(st[j]==' ' && st[j+1]!=' ')
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
     xuli();
     return 0;
 }
