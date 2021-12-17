#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string st;
string ans;

void nhap()
{
    ifstream f;
    f.open("XAUDX.INP");
    f>>st;
    f.close();
}

bool doixung(string st)
{
    string doixung="";
    for(int x=st.length()-1;x>=0;x--)
    {
        doixung=doixung+st[x];;
    }
    if(st==doixung)
        return 1;
    else
        return 0;

}

bool doixungcuadoixung(string st)
{
    int half=st.length()/2;
    if(st.length()%2!=0)
        half++;
    string half_st;
    for(int x=0;x<half;x++) 
        half_st=half_st+st[x];
    if(doixung(half_st))
        return 1;
    else
        return 0;
}

void xuli()
{
    if(doixung(st) && doixungcuadoixung(st))
        ans="YES";
    else
        ans="NO";
}

void xuat()
{
    ofstream f;
    f.open("XAUDX.OUT");
    f<<ans<<endl;
    f.close();
}

int main()
{
    nhap();
    xuli();
    xuat();
    return 0;
}
