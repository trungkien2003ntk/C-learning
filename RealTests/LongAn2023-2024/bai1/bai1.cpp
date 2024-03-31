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
long long k, lf, rg;
vector<char> pr;
vector<string> res, initST;
string tempt;

// Segment Sieve of eratostenes

vector<char> segmentedSieve(long long L, long long R)
{
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i)
    {
        if (!mark[i])
        {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<char> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
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
    lf = pow(10, 2 * k), rg = lf * 10 - 1;
    pr = segmentedSieve(lf, rg);
    buildST();

    // for (auto it : initST)
    //     cout << it << " ";

    for (int i = 0; i < initST.size(); i++)
        if (pr[stoi(initST[i]) - lf])
            res.push_back(initST[i]);

    cout << res.size() << "\n";
    for (auto it : res)
        cout << it << " ";
    // getchar();
}