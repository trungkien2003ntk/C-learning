#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1;

int n, m, q, a[N], b[N], cnt[3 * N], queries[N];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    memset(b, 0, sizeof b);
    memset(cnt, 0, sizeof cnt);

    cin >> n >> m >> q;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    while(m--) {
        int u, v, k;
        cin >> u >> v >> k;
        b[u] += k;
        b[v + 1] -= k;
    }

    int Amin = 1e9;
    for(int i = 1; i <= n; ++i)
        b[i] += b[i - 1],
        Amin = min(Amin, a[i] + b[i]);
    for(int i = 1; i <= q; ++i) cin >> queries[i], Amin = min(Amin, queries[i]);
    for(int i = 1; i <= n; ++i) ++cnt[a[i] + b[i] - Amin];

    for(int i = 1; i <= q; ++i) cout << cnt[queries[i] - Amin] << ' ';

    return 0;
}
