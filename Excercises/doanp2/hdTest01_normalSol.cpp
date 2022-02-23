#include <bits/stdc++.h>

using namespace std;
int n, dat[12], dat_sep[12],dat_counter[12];

void nhap()
{
    ifstream f("ipTest01.in");
    for (int i = 1; i <= 10; i++)
        f >> dat[i];
    f.close();
}

void xuly()
{
    int kt = false;
    int csb = 0;
    for (int i = 1; i <= 10; i++)
    {
        kt = true;
        for (int j = 1; j <= csb; j++)
            if (dat_sep[j] == dat[i])
            {
                kt = false;
                break;
            }
        if (kt){
            csb++;
            dat_sep[csb] = dat[i];
        }
    }
    for (int i = 1;i<= csb; i++)
        for (int j= 1;j<=10;j++)
            if (dat[j] == dat_sep[i])
                dat_counter[i]++;
    
    for (int i =1;i<=csb;i++)
        cout << dat_sep[i] << " " << dat_counter[i] << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    nhap();
    xuly();
    return 0;
}