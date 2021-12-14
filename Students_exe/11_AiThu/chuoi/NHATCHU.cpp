#include<iostream>
#include<string>

using namespace std;

string xau;

void nhap()
{
    getline(cin,xau);
}

bool datrongmang(int tong)
{
    if (tong!=0)
        return true;
    return false;
}

void nhatchu()
{
    int danhdau[123];
    string chuoi="";
    fill_n(danhdau,123,0);
    for (int i=0;i<xau.size();i++)
    {
        if (!datrongmang(danhdau[xau[i]]))
            chuoi+=xau[i];
        danhdau[xau[i]]++;
    }
    cout <<chuoi;
}

int main()
{
    nhap();
    nhatchu();
    return 0;
}
