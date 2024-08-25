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
long long res = 0, arX[1008], arY[1008], N, csX = 1, csY = 1;
int main()
{
    fast_io;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arX[i];
    for (int i = 1; i <= N; i++)
        cin >> arY[i];

    while (csX <= N && csY <= N)
    {
        while (arX[csX] > arY[csX] && csX <= N && csY <= N)
            csX++;
        csY = csX;
        // cout << csX << "\n";
        while (arX[csX] <= arY[csY] && csX <= N && csY <= N)
            csY++;
        // cout << csX << " " << csY << endl;
        res += (res == 0 ? csY - csX - 1 : min(res, csY - csX - 1));
    }
    cout << res;
    // getchar();
}