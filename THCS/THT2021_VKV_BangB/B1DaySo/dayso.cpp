#include <unordered_map>
#include <iostream>

using namespace std;

template <typename T>
void maximize(T &res, const T &val)
{
    if (res < val)
        res = val;
}
template <typename T>
void minimize(T &res, const T &val)
{
    if (res > val)
        res = val;
}
typedef long long ll;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n;
int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    cin >> n;

    ll s = 0;
    ll res = -LINF;
    unordered_map<int, ll> M;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;

        if (M.count(x) == false)
        {
            M[x] = s;
        }
        else
        {
            maximize(res, s - M[x] + x);
            minimize(M[x], s);
        }

        s += x;
    }

    cout << res;
    return 0;
}