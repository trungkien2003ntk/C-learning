#include <bits/stdc++.h>
#include <vector>
// Policy-based data structures - Co the build indexed_set
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
using namespace std;
// Pre Definitions DATA TYPES
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;
// Pre Definitions CONSTANTS
#define FT front()
#define BK back()
#define PF push_front
#define EB emplace_back
#define LB lower_bound
#define UB upper_bound
#define MOD 1e9 + 7
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define uniq(x) x.erase(unique(all(x)), x.end());
#define sz(x) (ll)(x).size()
#define all_r(x) x.rbegin(), x.rend()
#define clr(a) memset((a), 0, sizeof(a))
#define rsz resize
#define ins insert
// Graph transitions
// vector<pair<int, int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
// vector<pair<int, int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// Return wherehter an array contains an element with value x
#define FIND_X(vec, x) lower_bound(vec.begin(), vec.end(), x) - vec.begin();
// Return wherehter an array contains an element with value x return upper bound of item x
#define FIND_UB_X(vec, x) upper_bound(vec.begin(), vec.end(), x) - vec.begin();
// SPEED UP
#pragma GCC optimize("O3") // how good is this? lol
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
// Operations on bits
#define popcnt(x) __builtin_popcount(x)
#define popcntll(x) __builtin_popcountll(x)
#define trailz(x) __builtin_ctz(x)
#define trailzll(x) __builtin_ctzll(x)
#define leadz(x) __builtin_clz(x) // REMEMBER THE X SHOULD BE UNSIGNED
#define leadzll(x) __builtin_clzll(x)
#define oddparity(x) __builtin_parity(x)
// Define common use loops and functions
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPLL(i, a, b) for (ll i = a; i < b; i++)
#define SQ(a) (a) * (a);
#define output_all_vec(x)              \
    for (int i = 0; i < x.size(); i++) \
        cout << x[i] << " ";           \
    cout << endl;
// Some common templates
template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (auto &i : v)
        is >> i;
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> v)
{
    for (auto &i : v)
        os << i << ' ';
    return os;
}
template <typename T, size_t sz>
istream &operator>>(istream &is, array<T, sz> &v)
{
    for (auto &i : v)
        is >> i;
    return is;
}
template <typename T, size_t sz>
ostream &operator<<(ostream &os, array<T, sz> v)
{
    for (auto &i : v)
        os << i << ' ';
    return os;
}
template <class T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using MaxHeap = priority_queue<T, vector<T>, less<T>>;
template <typename I>
struct _reversed_struct
{
    I &v_;
    explicit _reversed_struct(I &v) : v_{v} {}
    typename I::reverse_iterator begin() const { return v_.rbegin(); }
    typename I::reverse_iterator end() const { return v_.rend(); }
};
template <typename I>
_reversed_struct<I> reversed(I &v) { return _reversed_struct<I>(v); }
template <typename T>
void ckmin(T &a, const T &b) { a = min(a, b); }
template <typename T>
void ckmax(T &a, const T &b) { a = max(a, b); }
template <typename T, typename P>
T cceil(const T &a, const P &b)
{
    ll x = a, y = b;
    return (x + y - 1) / y;
}
// Calculate lcm and gcd
int gcd(int a, int b)
{
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
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
int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}
//============================================================================
// START PROGRAM
//============================================================================
int n, m, cs = 0, csMaxFactor = 0;

const int N = 100008;
const int kMax = ceil((N + 1) / 6);
int countFactors[kMax + 1], needPrime[kMax + 1];
bool prime[N];

// Sàn Eratosthenes bản cải tiến
inline void initPrimes()
{
    memset(prime, 0, sizeof(prime));
    prime[2] = prime[3] = 1;
    // k=1668: 6k+1 = 10009; 6k-1 = 10007 đã vượt giới hạn tính
    // 6k+1 và 6k-1 không chia hết cho 2;3 nên khỏi kiểm tra
    for (int k = 1; k <= kMax; k++)
        prime[6 * k + 1] = prime[6 * k - 1] = 1;
    int t1, t2;
    for (int k = 1; k <= kMax; k++)
    {
        t1 = 6 * k - 1, t2 = 6 * k + 1;
        if (prime[t1])
            for (int j = k + 1; j <= kMax; j++)
            {
                if ((6 * j + 1) % t1 == 0)
                    prime[6 * j + 1] = 0;
                if ((6 * j - 1) % t1 == 0)
                    prime[6 * j - 1] = 0;
            }
        if (prime[t2])
            for (int j = k + 1; j < kMax; j++)
            {
                if ((6 * j + 1) % t2 == 0)
                    prime[6 * j + 1] = 0;
                if ((6 * j - 1) % t2 == 0)
                    prime[6 * j - 1] = 0;
            }
    }
    // Reload into needPrime array
    for (int i = 1; i < N; i++)
        if (prime[i])
            needPrime[++cs] = i;

    // Checker
    // for (int i = 1;i<=cs;i++)
    //     cout << needPrime[i] << " ";
}

int calcSum(int x)
{
    int kq = 1;
    memset(countFactors, 0, sizeof(countFactors));
    csMaxFactor = 1;
    while (x > 1)
        if (x % needPrime[csMaxFactor] == 0)
            x /= needPrime[csMaxFactor], countFactors[csMaxFactor]++;
        else
            csMaxFactor++;

    for (int i = 1; i <= csMaxFactor; i++)
        if (countFactors[i])
            kq *= (1 - pow(needPrime[i], countFactors[i] + 1)) / (1 - needPrime[i]);
    return kq;
}

int32_t main()
{
    fast_io;

    initPrimes();
    cin >> n;
    m = n + 1;
    while (((calcSum(m) * n) != (calcSum(n) * m)) && (m < 100000))
        m++;
    if (m <= 100000)
        cout << m;
    else
        cout << -1;
    // getch();
}
