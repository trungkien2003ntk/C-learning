#include<iostream>
#include<string>

using namespace std;

int T,tong;
string xau[101];

void nhap()
{
    cin>> T;
    cin.ignore();
    for (int i=1;i<=T;i++)
    {
        getline(cin,xau[i]);
    }
}

void xuly()
{
    for (int i=1;i<=T;i++)
    {
        tong=0;
        for (int j=0;j<xau[i].size();j++)
        {
            if (xau[i][j]==' '&&xau[i][j+1]!=' ')
                tong++;
        }
        cout <<tong <<endl;
    }
}

int main()
{
    nhap();
    xuly();
    return 0;
}
