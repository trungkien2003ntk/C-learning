#include<iostream>
#include<string>

using namespace std;

string xau;
int T,L,R;

void nhap()
{
    cin >>xau;
    cin >>T;
}

string catchuoi(string st,int a,int b)
{
    st=st.substr(a-1,b-a+1);
    return st;
}

bool check(string st)
{
    string chuoi1="";
    for (int i=st.size()-1;i>=0;i--)
    {
        chuoi1+=st[i];
    }
    if (chuoi1==st)
        return true;
    return false;
}

void xuly()
{
    int cs=0;
    string kq,arr[5001],chuoi;
    for (int i=1;i<=T;i++)
    {
        cin >>L >>R;
        chuoi=catchuoi(xau,L,R);
        if (check(chuoi))
        {
            kq="YES";
            cs++;
            arr[cs]=kq;
        }
        else
        {
            kq="NO";
            cs++;
            arr[cs]=kq;
        }
    }
    for (int i=1;i<=cs;i++)
    {
        cout <<arr[i] <<endl;
    }
}

int main()
{
    nhap();
    xuly();
    return 0;
}
