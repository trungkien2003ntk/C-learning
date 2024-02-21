#include <bits/stdc++.h>

using namespace std;
long long n, x, a[100000];

bool check(long long m) {
    long long tong = 0;
    for (long long i = 0; i < n; i++) {
        tong += (a[i] / m);
    }

    if (tong >= x) return 1;
    return 0;
}

int32_t main() {
    cin >> n >> x;
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long l = 1, r = 1000000000, res = 0;

    while (l <= r) {
        long long m = (l + r) / 2;
        if (check(m)) {
            res = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    cout << res << endl;
}