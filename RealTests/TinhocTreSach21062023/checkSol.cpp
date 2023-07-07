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
//============================================================================
// START PROGRAM
//============================================================================
int T;
string s[18];
int space[18];

int main()
{
    fast_io;
    cin >> T;
    for (int i = 1; i <= T; i++)
        cin >> s[i] >> space[i];

    for (int cs = 1; cs <= T; cs++)
    {
        // Cooked Raw Dat
        // Calculate amount of cargo and space
        int pos = 0, n = 0, dat[500008];
        memset(dat, 0, sizeof(dat));
        char item = s[cs][0];
        while (pos < s[cs].size())
        {
            item = s[cs][pos];
            if (pos < s[cs].size())
                n++;

            while ((s[cs][pos] == item) && (pos < s[cs].size()))
            {
                dat[n]++;
                pos++;
            }
            if (pos < s[cs].size())
                n++;

            item = s[cs][pos];
            while (s[cs][pos] == item && pos < s[cs].size())
            {
                dat[n]++;
                pos++;
            }
        }

        // Handle
        int max_con_spare = 0, cur_space, load, l_moved, r_moved, st_pos, end_pos, res;
        unordered_map<int, bool> pos_moved;
        if (s[cs][0] == '.')
            for (int i = 1; i <= n; i += 2)
                max_con_spare = max(max_con_spare, dat[i]);
        else
            for (int i = 2; i <= n; i += 2)
                max_con_spare = max(max_con_spare, dat[i]);
        if (max_con_spare >= space[cs])
            cout << 0 << "\n";
        else
        {
            // Setup để st_pos luôn nằm ở vị trí space, end_pos luôn nằm ở vị trí cargo
            if (s[cs][0] == '.')
                cur_space = dat[1], load = 0, l_moved = 0, r_moved = 0, st_pos = 1, end_pos = 2, res = INT_MAX;
            else
                cur_space = dat[2], load = 0, l_moved = 0, r_moved = 0, st_pos = 2, end_pos = 3, res = INT_MAX;
            while (end_pos < n)
            {
                while (end_pos < n && cur_space + dat[end_pos + 1] < space[cs])
                {
                    if (dat[end_pos] * dat[end_pos + 1] >= cur_space * dat[end_pos])
                    {
                        pos_moved[end_pos] = false;
                        l_moved += cur_space * dat[end_pos];
                    }
                    else
                    {
                        pos_moved[end_pos] = true;
                        r_moved += dat[end_pos] * dat[end_pos + 1];
                    }
                    cur_space += dat[end_pos + 1];
                    end_pos += 2;
                }
                // Khi biết chắc tại dat[end_pos+1] đủ để đáp ứng bằng hoặc hơn space[cs] thì trả kết quả
                load = min(dat[end_pos] * (space[cs] - cur_space), cur_space * dat[end_pos]);
                res = min(res, load + l_moved + r_moved);
                cout << res << "\n";
                load = 0;

                // Tăng end_pos để lấy toàn bộ vùng trống kề sau end_pos
                if (dat[end_pos] * dat[end_pos + 1] >= cur_space * dat[end_pos])
                {
                    pos_moved[end_pos] = false;
                    l_moved += cur_space * dat[end_pos];
                }
                else
                {
                    pos_moved[end_pos] = true;
                    r_moved += dat[end_pos] * dat[end_pos + 1];
                }
                cur_space += dat[end_pos + 1];
                end_pos += 2;

                // Tăng st_pos để xử lý cho trường hợp tiếp theo
                while (st_pos < end_pos && cur_space >= space[cs])
                {
                    cur_space -= dat[st_pos];
                    if (pos_moved[st_pos + 1])
                        r_moved -= dat[st_pos + 1] * dat[st_pos + 2];
                    else
                        l_moved -= dat[st_pos + 1] * dat[st_pos];
                    st_pos += 2;
                }
            }
            cout << res << "\n";
        }

        for (int i = 1; i <= n; i++)
            cout << dat[i] << " \n"[i == n];
        for (int i = 1;i<=n;i++)
            cout << pos_moved[i] << " \n"[i==n];
    }

    // getchar();
}