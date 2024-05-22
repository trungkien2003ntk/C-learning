#include <bits/stdc++.h>
#include <vector>
// Policy-based data structures - Co the build indexed_set
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
using namespace std;

// SPEED UP
// #pragma GCC optimize("O3") // how good is this? lol
// #pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
// #pragma GCC optimize("unroll-loops")
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

// Calculate lcm and gcd
long long gcd(long long a, long long b)
{
    if (!a || !b)
        return a | b;
    unsigned long long shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do
    {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}
long long lcm(long long a, long long b)
{
    return a / gcd(a, b) * b;
}
//============================================================================
// START PROGRAM
//============================================================================

const long long MAX_SIZE = 10000001;
// isPrime[] : isPrime[i] is true if number is prime
// prime[] : stores all prime number less than N
// SPF[] that store smallest prime factor of number
// [for Exp : smallest prime factor of '8' and '16'
// is '2' so we put SPF[8] = 2 , SPF[16] = 2 ]
vector<long long> isprime(MAX_SIZE, true);
vector<long long> prime;
vector<long long> SPF(MAX_SIZE);

// function generate all prime number less than N in O(n)
void manipulated_seive(long long N)
{
    // 0 and 1 are not prime
    isprime[0] = isprime[1] = false;
    // Fill rest of the entries
    for (long long i = 2; i < N; i++)
    {
        // If isPrime[i] == True then i is prime number
        if (isprime[i])
        {
            // put i into prime[] vector
            prime.push_back(i);
            // A prime number is its own smallest
            // prime factor
            SPF[i] = i;
        }
        // Remove all multiples of i*prime[j] which are
        // not prime by making isPrime[i*prime[j]] = false
        // and put smallest prime factor of i*Prime[j] as prime[j]
        // [ for exp :let i = 5 , j = 0 , prime[j] = 2 [ i*prime[j] = 10 ]
        // so smallest prime factor of '10' is '2' that is prime[j] ]
        // this loop run only one time for number which are not prime
        for (long long j = 0; j < (long long)prime.size() && i * prime[j] < N && prime[j] <= SPF[i]; j++)
        {
            isprime[i * prime[j]] = false;
            // put smallest prime factor of i*prime[j]
            SPF[i * prime[j]] = prime[j];
        }
    }
}

long long a, b, c, maxabc, lcmabc;
double res;
map<long long, long long> prCs;
signed main()
{
    fast_io;
    cin >> a >> b >> c;
    maxabc = max(max(a, b), c);
    manipulated_seive(maxabc + 1);
    lcmabc = lcm(a, lcm(b, c));

    for (long long i = 0; i < prime.size(); i++)
    {
        if (lcmabc % prime[i] == 0)
            prCs[prime[i]] = 0;
        while (lcmabc % prime[i] == 0)
        {
            prCs[prime[i]]++;
            lcmabc /= prime[i];
        }
    }

    res = 1;
    for (auto it : prCs)
        if (it.second & 1)
            res *= pow(it.first, (it.second + 1) / 2);
        else
            res *= pow(it.first, it.second / 2);

    cout << fixed << setprecision(0) << res;
    // getchar();
}