#include<iostream>
#include<string>
using namespace std;

string st;
int tong;
void nhap()
{
    cin.ignore();
    getline(cin,st);
}
void xuli()
{
    tong=0;
    st+=" ";
    for(int i=0;i<=st.size()-1;i++)
        {
            if(st[i+1]==' '&& st[i]!=' ')
                tong++;
        }
    cout << tong;
}
 int main()
 {
     nhap();
     xuli();
     return 0;
 }
