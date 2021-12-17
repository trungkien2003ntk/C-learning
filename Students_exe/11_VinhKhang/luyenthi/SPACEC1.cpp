#include<iostream>
#include<string>
using namespace std;
int T;
int tong=0;
string s[101];
void nhap()
{
    cin>>T;
    cin.ignore();
    for(int i=1;i<=T;i++)
    {
         getline(cin,s[i]);
    }
//    for(int i=1;i<=T;i++)
//    {
//        cout << s[i];
//    }
}
void xuli()
{
    for(int i=1;i<=T;i++)
    {
        tong=0;
        for(int j=0;j<s[i].size();j++)
        {
            if(s[i][j]==' '&& s[i][j+1]!=' ')
                tong++;
        }
        cout << tong << endl;
    }
}
int main()
{
    nhap();
    xuli();
    return 0;
}
