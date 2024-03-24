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
// Group choice
long long tempt, n, k, csPos, csNeg, res, calcPos, calcNeg;
vector<int> posNum, negNum;
int main()
{
    fast_io;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> tempt;
        if (tempt >= 0)
            posNum.push_back(tempt);
        else
            negNum.push_back(-tempt);
    }
    // Sort decending - sắp xếp giảm dần
    sort(posNum.rbegin(), posNum.rend());
    sort(negNum.rbegin(), negNum.rend());

    csPos = csNeg = res = 0;
    while (k--)
    {
        calcPos = posNum[csPos] * posNum[csPos + 1] * posNum[csPos + 2];
        calcNeg = posNum[csPos] * negNum[csNeg] * negNum[csNeg + 1];
        if (calcPos > calcNeg)
            res += calcPos, csPos += 3;
        else
            res += calcNeg, csPos++, csNeg += 2;
    }
    cout << res;
    // getchar();
}