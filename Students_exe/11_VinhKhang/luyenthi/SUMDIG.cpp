#include<iostream>
#include<string>
using namespace std;
int T;
string st;
int cs=0;
string arr[100000];
int kq[100000];
void nhap()
{
    cin>>T;
    cin.ignore();
    for(int i=1;i<=T;i++)
    {
        cin>>arr[i];
    }
}
int tinh(string x)
{
    int so,tong=0;
    for(int i=0;i<=x.size()-1;i++)
    {
        so=x[i]-'0';
        tong+=so;
    }
    return tong;
}
void xuli()
{
    for(int i=1;i<=T;i++)
        {
            cs++;
            kq[cs]=tinh(arr[i]);
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
