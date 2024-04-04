#include <bits/stdc++.h>
#define FOR(i, k, n) for (int i = k; i <= n; i++)
#define FORR(i, k, n) for (int i = n; i >= k; i--)
#define pb push_back
#define all(x) begin(x), end(x)
#define fi first
#define se second
#define BIT(S, i) (((S) >> (i)) & 1)
#define MASK(i) ((1ll) << (i))
#define name "loopy"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

template <class T>
bool maximize(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

template <class T>
bool minimize(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

struct Bignum
{
    static const int BASE = (int)1e9;
    static const int MAX_DIGIT = 100;
    int digits[MAX_DIGIT], numDigit;
    Bignum() {}
    Bignum(long long x)
    {
        numDigit = 0;
        memset(digits, 0, sizeof digits);
        if (x == 0)
            numDigit = 1;
        while (x > 0)
        {
            digits[numDigit++] = x % BASE;
            x /= BASE;
        }
    }
    Bignum(string x)
    {
        numDigit = 0;
        memset(digits, 0, sizeof digits);
        if (x == "0")
            numDigit = 1;
        for (int i = (int)x.size() - 1; i >= 0; i--)
        {
            int j = max(i - 9 + 1, 0);
            int num = 0;
            for (int k = j; k <= i; k++)
                num = 10 * num + (x[k] - '0');
            digits[numDigit++] = num;
            i = j;
        }
    }
    Bignum &operator+=(const Bignum &x)
    {
        numDigit = max(numDigit, x.numDigit);
        int carry = 0;
        for (int i = 0; i < numDigit; i++)
        {
            digits[i] += x.digits[i] + carry;
            if (digits[i] >= BASE)
            {
                digits[i] -= BASE;
                carry = 1;
            }
            else
                carry = 0;
        }
        if (carry > 0)
            digits[numDigit++] = carry;
        return *this;
    }
    Bignum operator+(const Bignum &x) const
    {
        Bignum res = *this;
        return res += x;
    }

    Bignum &operator-=(const Bignum &x)
    {
        int remain = 0;
        for (int i = 0; i < numDigit; i++)
        {
            digits[i] -= x.digits[i] + remain;
            if (digits[i] < 0)
            {
                digits[i] += BASE;
                remain = 1;
            }
            else
                remain = 0;
        }
        while (numDigit > 1 && digits[numDigit - 1] == 0)
            numDigit--;
        return *this;
    }
    Bignum operator-(const Bignum &x) const
    {
        Bignum res = *this;
        return res -= x;
    }

    Bignum operator*(const Bignum &x) const
    {
        if (*this == 0 | x == 0)
            return Bignum(0LL);

        Bignum res(0LL);
        for (int i = 0; i < numDigit; i++)
            for (int j = 0; j < x.numDigit; j++)
            {
                long long tmp = 1LL * digits[i] * x.digits[j];
                int pos = i + j;
                while (tmp > 0)
                {
                    tmp += res.digits[pos];
                    res.digits[pos] = tmp % BASE;
                    tmp /= BASE;
                    pos++;
                }
            }
        res.numDigit = numDigit + x.numDigit - 1;
        if (res.digits[res.numDigit] > 0)
            res.numDigit++;
        return res;
    }

#define COMPARE(x, y) (((x) > (y)) - ((x) < (y)))
    int compare(const Bignum &x) const
    {
        if (numDigit != x.numDigit)
            return COMPARE(numDigit, x.numDigit);
        for (int i = numDigit - 1; i >= 0; i--)
            if (digits[i] != x.digits[i])
                return COMPARE(digits[i], x.digits[i]);
        return 0;
    }

#define DEFINE_OPERATOR(o) \
    bool operator o(const Bignum &x) const { return compare(x) o 0; }
    DEFINE_OPERATOR(>)
    DEFINE_OPERATOR(>=) DEFINE_OPERATOR(==)
        DEFINE_OPERATOR(<) DEFINE_OPERATOR(<=) DEFINE_OPERATOR(!=)
#undef DEFINE_OPERATOR

            string toString(void) const
    {
        string res;
        for (int i = 0; i < numDigit; i++)
        {
            int x = digits[i];
            for (int love = 0; love < 9; love++)
            {
                res.push_back('0' + x % 10);
                x /= 10;
            }
        }
        while (res.size() > 1 && res.back() == '0')
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};

const int N = 31;
Bignum dp[N], f[N], what, ans;
string s;
int n;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen(name".inp","r",stdin);
    // freopen(name".out","w",stdout);
    cin >> s;
    what = Bignum(s);
    n = s.size();
    s = '0' + s;
    f[0] = Bignum(1);
    dp[0] = Bignum(0);
    FOR(i, 1, n)
    {
        f[i] = f[i - 1] * Bignum(2);
        dp[i] = Bignum(11) * dp[i - 1] + Bignum(s[i] - 48) * f[i - 1];
    }
    ans = dp[n] - what;
    cout << ans.toString();
}