#include <iostream>
#include <string>
#include <math.h>

using namespace std;
int ptich(long long k, int n)
{
    int q = 0;
    while (n * pow(2, q) <= k)
        q++;
    return q - 1;
}
int baitapDat()
{
    long long k;
    string s;
    cin >> k >> s;
    int n = s.size();
    if (k <= n)
        cout << s[k - 1];
    else if (n == 1)
    {
        cout << s[0];
    }
    else
    {
        while (k > n)
        {
            int q = ptich(k, n);
            long long m = pow(2, q) * n;
            long long r = k - m;
            if (r == 0)
                k = k / 2 - 1;
            else if (r == 1)
                k = k - 1;
            else
                k = r - 1;
        }
        cout << s[k - 1];
    }
    return 0;
}