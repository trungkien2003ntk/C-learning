#include <bits/stdc++.h>

using namespace std;
int n, dat[12], dat_counter[12];

void nhap()
{
    ifstream f("ipTest01.in");
    for (int i = 1; i <= 10; i++)
        f >> dat[i];
    f.close();
}

void xuly()
{
    set<int> setofDat{begin(dat), end(dat)};
    vector<int> vec{setofDat.begin(), setofDat.end()};
    for (int &p : vec)
        cout << p << " ";
    cout << endl;
    for (int i = 1; i <= 10; i++)
        dat_counter[find(vec.begin(), vec.end(), dat[i]) - vec.begin()]++;
    for (int i = 1; i < vec.size(); i++)
        cout << vec[i] << " " << dat_counter[i] << endl;
}

int main()
{
    nhap();
    xuly();
    return 0;
}