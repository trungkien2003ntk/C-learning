#include <bits/stdc++.h>
#include <set>
using namespace std;

int n, dat[200];
bool dat_check[200];
set<int> dat_total;

void nhap()
{
    ifstream f("bai3.inp");
    f >> n;
    for (int i = 1; i <= n; i++)
        f >> dat[i];
    f.close();
}

void xuly(int x, int current_sum)
{
    int i = x;
    while (i <= n)
    {
        if (dat_check[i] == 0)
        {
            dat_check[i] = 1;
            current_sum += dat[i];
            dat_total.insert(current_sum);
            xuly(i+1, current_sum);
            current_sum -= dat[i];
            dat_check[i] = 0;
        }
        i++;
    }
}

int main()
{
    nhap();
    xuly(1,0);
    set<int>::iterator it;
    cout << endl;
    cout << dat_total.size();
    return 0;
}