#include <bits/stdc++.h>
#include <vector>
using namespace std;
// SPEED UP
// #pragma GCC optimize("O3") //how good is this? lol
// #pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
// #pragma GCC optimize("unroll-loops")
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
//============================================================================
// START PROGRAM
//============================================================================
long long k;
vector<char> pr;
vector<string> res, initST;
string tempt;

bool isPrime(long long x)
{
    if (x == 2 || x == 3)
        return true;
    else if (x < 2 || x % 2 == 0 || x % 3 == 0)
        return false;
    else
    {
        bool kq = true;
        for (long long i = 1; i <= (sqrt(x) + 1) / 6; i++)
            if ((x % (6 * i + 1) == 0) || (x % (6 * i - 1) == 0))
            {
                kq = false;
                break;
            }
        return kq;
    }
}

void buildST()
{
    for (int i = 1; i <= 9; i++)
        for (int j = 0; j <= 9; j++)
            if (j != i)
            {
                tempt = "";
                for (int cs = 1; cs <= 2 * k + 1; cs++)
                    tempt += to_string(i);
                tempt[k] = to_string(j)[0];
                initST.push_back(tempt);
            }
}
int main()
{
    fast_io;
    cin >> k;
    buildST();
    for (long long i = 0; i < initST.size(); i++)
        if (isPrime(stoll(initST[i])))
            res.push_back(initST[i]);
    cout << res.size() << "\n";
    for (auto it : res)
        cout << it << " ";
    // getchar();
}