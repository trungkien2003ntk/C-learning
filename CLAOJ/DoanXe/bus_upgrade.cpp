#include <bits/stdc++.h>
#include <vector>
using namespace std;
// SPEED UP
#pragma GCC optimize("O3") // how good is this? lol
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
//============================================================================
// START PROGRAM
//============================================================================
int n, m, k, mid, low, high, mid1, mid2;
vector<int> a;

bool is_valid_separation(int kt, int distance_limit, int mt)
{
    int subarray_start = 0;
    int subarray_count = 1; // Initialize with 1 subarray

    int i = 0;
    while (i < n && subarray_count <= mt)
    {
        if (i + 1 < n && (a[i + 1] - a[subarray_start] > distance_limit || i + 1 - subarray_start == kt))
        {
            subarray_start = i + 1;
            subarray_count++;
        }
        i++;
    }
    return subarray_count <= mt;
}

int main()
{
    fast_io;
    cin >> n >> m >> k;
    a.resize(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    // BST to find minimum distance ternary search
    low = 0;
    high = a[n - 1] - a[0]; // Maximum possible distance

    while (low <= high)
    {
        mid1 = low + (high - low) / 3;
        mid2 = high - (high - low) / 3;

        if (is_valid_separation(k, mid1, m))
            // P can be potentially lower, explore left side
            high = mid1 - 1;
        else if (is_valid_separation(k, mid2, m))
            // P needs to be higher to satisfy separation with at most m subarrays, explore right side
            low = mid1 + 1, high = mid2 - 1;
        else
            low = mid2 + 1;
    }

    cout << low;
    // getchar();
}