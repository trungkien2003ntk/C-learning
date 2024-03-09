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
long long n, m, k, res = 1e16, mid;
vector<long long> a;

int main()
{
    fast_io;
    cin >> n >> m >> k;
    a.resize(n);
    a.reserve(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    // Checkpoint
    for (int i = 0; i < n; i++)
        cout << a[i] << " \n"[i == n - 1];

    // If number of cars >= number of person then each person get on 1 car without waiting
    if (m >= n)
        cout << 0;
    else
    {
        // BST
        int left = 0, right = max(a[n - 1] - a[m - 1], a[n - (m - 1)] - a[0]);
        cout << left << " " << right << endl;

        // while (left <= right)
        // {
        //     mid = (left + right) >> 1;
        //     // Vấn đề 1: Làm sao xác định được cái mid này có tồn tại hay không?
        //     // Vấn đề 2: Cái mid này có phải là thời gian chờ tối đa của một trường hợp nào đó không?
        //     // Vấn đề 3: Làm sao để biết có cái trường hợp nào tốt hơn cái mid này không?
        //     // Vấn đề 4: Theo sau vấn đề 3, khi nào sẽ không thể có trường hợp như thế được nữa?
        // }
    }

    // getchar();
}