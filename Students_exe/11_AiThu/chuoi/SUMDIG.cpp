#include<iostream>

using namespace std;

unsigned long T,res[1000000],cs=0;
string n,arr[1000000];

void nhap()
{
    cin >>T;
    cin.ignore();
    for (int i=1;i<=T;i++)
        getline(cin,arr[i]);
}

int tongchuso(string str)
{
    int tong=0,so;
    for (int i=0;i<str.size();i++)
    {
        so=str[i]-'0';
        tong+=so;
    }
    return tong;
}

void xuat()
{
    for (int j=1;j<=T;j++)
    {
        cs++;
        res[cs]=tongchuso(arr[j]);
    }
    for (int j=1;j<=T;j++)
    {
        cout <<res[j] <<endl;
    }
}

int main()
{
    nhap();
    xuat();
    return 0;
}
