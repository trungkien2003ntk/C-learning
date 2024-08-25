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
int n, m, k, mid;
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

int find_min_distance(int kt, int mt)
{
    int low = 0;
    int high = a[n - 1] - a[0]; // Maximum possible distance

    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (is_valid_separation(kt, mid, mt))
            // P can be potentially lower, explore left side
            high = mid - 1;
        else
            // P needs to be higher to satisfy separation with at most m subarrays, explore right side
            low = mid + 1;
    }

    return low;
}

int main()
{
    fast_io;
    cin >> n >> m >> k;
    a.resize(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    cout << find_min_distance(k, m);
    // getchar();
}