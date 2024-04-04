#include <bits/stdc++.h>
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

string strDiv2(string x)
{
    string result = "";
    long long tempt = x[0] - '0', val;
    if (tempt >= 2)
    {
        result += to_string(tempt / 2);
        tempt %= 2;
    }
    for (long long i = 1; i < x.length(); i++)
    {
        val = 10 * tempt + (x[i] - '0');
        result += to_string(val / 2);
        tempt = val % 2;
    }
    return (result == "") ? "0" : result;
}

// This function support for the Multiply function below

string strSum(string x, string y)
{
    string result = "", remaining;
    long long limit = min(x.size(), y.size()), tempt = 0;
    for (int i = 0; i < limit; i++)
    {
        tempt = (x[x.size() - 1 - i] - '0') + (y[y.size() - 1 - i] - '0') + tempt;
        result = (char)(tempt % 10 + '0') + result;
        tempt /= 10;
    }
    if (x.size() != y.size())
    {
        (x.size() > y.size()) ? remaining = x : remaining = y;
        for (int i = remaining.size() - 1 - limit; i >= 0; i--)
        {
            tempt = remaining[i] - '0' + tempt;
            result = (char)(tempt % 10 + '0') + result;
            tempt /= 10;
        }
    }
    if (tempt)
        result = to_string(tempt) + result;
    return result;
}

string support_MulWithADigit(string x, char digit)
{
    if (digit == '0')
        return "0";
    else
    {
        string result = "";
        int tempt = 0;
        for (long long i = x.size() - 1; i >= 0; i--)
        {
            tempt = (x[i] - '0') * (digit - '0') + tempt;
            result = (char)(tempt % 10 + '0') + result;
            tempt /= 10;
        }
        if (tempt > 0)
            result = (char)(tempt % 10 + '0') + result;
        return result;
    }
}

string strMul(string x, string y)
{
    string result = "0", addZero = "";
    if (x == "0" || y == "0")
        return "0";
    else if (x == "1")
        return y;
    else if (y == "1")
        return x;
    else
    {
        for (int i = y.size() - 1; i >= 0; i--)
        {
            result = strSum(result, support_MulWithADigit(x, y[i]) + addZero);
            addZero += "0";
        }
        return result;
    }
}

string strMinus(string x, string y)
{
    string result = "";
    bool sig = false;
    if (x.size() < y.size() || (x.size() == y.size() && x < y))
        swap(x, y), sig = true;

    long long limit = min(x.size(), y.size()), tempt = 0;
    for (int i = 0; i < limit; i++)
    {
        if (x[x.size() - 1 - i] - '0' >= y[y.size() - 1 - i] - '0' + tempt)
        {
            result = (char)((x[x.size() - 1 - i] - '0') - (y[y.size() - 1 - i] - '0') - tempt + '0') + result;
            tempt = 0;
        }
        else
        {
            result = (char)(10 + (x[x.size() - 1 - i] - '0') - (y[y.size() - 1 - i] - '0') - tempt + '0') + result;
            tempt = 1;
        }
    }

    if (x.size() > y.size())
        for (int i = x.size() - 1 - limit; i >= 0; i--)
            if (x[i] - '0' - tempt < 0)
            {
                result = (to_string)(10 + (x[i] - '0') - tempt) + result;
                tempt = 1;
            }
            else
            {
                result = to_string(x[i] - '0' - tempt) + result;
                tempt = 0;
            }

    while (result.size() > 1 && (result[0] == '0' || result[0] == ' '))
        result.erase(result.begin(), result.begin() + 1);
    if (sig)
        result = "-" + result;
    return result;
}

// Calculate numbers in string
string strPow(string base, string exponent)
{
    string result = "1";
    while (exponent != "0")
    {
        if ((exponent[exponent.size() - 1] - '0') % 2 == 1)
        {
            result = strMul(result, base);
            exponent = strMinus(exponent, "1");
        }
        else
        {
            base = strMul(base, base);
            exponent = strDiv2(exponent);
        }
    }
    return result;
}

string s, res;
int n;
int main()
{
    fast_io;
    cin >> s;
    n = s.size();
    res = "0";
    for (int i = 0; i < n; i++)
        res = strSum(res, support_MulWithADigit(strMinus(strMul(strPow("2", to_string(i)), strPow("11", to_string(n - i - 1))), strPow("10", to_string(n - i - 1))), s[i]));
    cout << res;
    // getchar();
}