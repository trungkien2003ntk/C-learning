// Created by Le Nguyen Phuong Vy
#include <bits/stdc++.h>
using namespace std;
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
const int N = 30;
Bignum dp[N + 5][N + 5], bug[N + 5], kq[N + 5], ans;
string s;
void debug()
{
    for (int i = 1; i <= N; ++i)
        dp[i][0] = Bignum(1);
    for (int i = 1; i <= N; ++i)
        dp[0][i] = Bignum(0);
    dp[0][0] = Bignum(1);
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (i < j)
            {
                dp[i][j] = Bignum(0);
                continue;
            }
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }
}
signed main()
{
    // freopen("ily2003.inp","r",stdin);
    // freopen("ily2003.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    int so = s.size();
    s = '#' + s;
    debug();
    ans = Bignum(0);
    bug[0] = Bignum(1);
    kq[0] = Bignum(1);
    for (int i = 1; i <= so; ++i)
        bug[i] = bug[i - 1] * Bignum(2);
    for (int i = 1; i <= so; ++i)
        kq[i] = kq[i - 1] * Bignum(10);
    for (int i = 1; i <= so; ++i)
    {
        Bignum the = Bignum(s[i] - '0') * bug[i - 1];
        for (int j = i; j <= so; ++j)
        {
            Bignum tong = dp[so - i][j - i];
            ans += tong * the * kq[so - j];
        }
    }
    for (int i = 1; i <= so; ++i)
    {
        Bignum the = Bignum(s[i] - '0');
        ans -= the * kq[so - i];
    }
    cout << ans.toString();
}