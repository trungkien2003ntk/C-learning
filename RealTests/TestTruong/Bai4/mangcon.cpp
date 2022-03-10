#include <bits/stdc++.h>
#include <string>
using namespace std;

string dat_st;

void nhap()
{
    cin >> dat_st;
}

void xuly()
{
    int kq = 0, i = 0;
    while (i <= dat_st.size())
    {
        int tempt = 0;
        set<char> items;
        while (i+tempt < dat_st.size() && items.find(dat_st[i + tempt]) == items.end())
        {
            items.insert(dat_st[i + tempt]);
            tempt++;
        }
        if (tempt > kq)
            kq = tempt;
        i++;
    }
    cout << kq;
}

int main()
{
    nhap();
    xuly();
    return 0;
}