#include<iostream>
#include<string>

using namespace std;

string st;

void nhap()
{
    getline(cin,st);
}

//bool lachu(string str)
//{
//    bool kq=false;
//    for (int i=0;i<st.size();i++)
//    {
//        if ('A'<=st[i]&&st[i]<='Z'||'a'<=st[i]&&st[i]<='z')
//            return true;
//    }
//    return false;
//}

void xuat()
{
    int tong=0;
    st+=" ";
    for (int i=0;i<=st.size();i++)
    {
        if (st[i]!=' '&&st[i+1]==' ')
            tong++;
    }
    cout <<tong;
}

int main()
{
    nhap();
    xuat();
    return 0;
}
