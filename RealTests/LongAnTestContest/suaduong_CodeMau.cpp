// Created by BJMinhNhut
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for(__typeof(b) i = a, _b = b; i <= _b; ++i) 
#define FORD(i, a, b) for(__typeof(a) i = a, _b = b; i >= _b; --i)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define MASK(i) (1ll<<(i))
#define BIT(t, i) (((t)>>(i))&1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;

/***Common Functions***/
template <class T>
bool minimize(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <class T>
bool maximize(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

/***End of Template***/

int n, m;
const int N = 2e5+4;
vi adj[N];
bool visited[N];

void Input() {
    cin >> n >> m;
    FOR(i, 1, m) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

void dfs(int u) {
    visited[u] = true;
    for(int v : adj[u]) if (!visited[v]) {
        dfs(v);
    }
}

void Solve() {
    memset(visited, 0, sizeof visited);
    int cnt = 0;
    FOR(i, 1, n) if (!visited[i]) {
        cnt++;
        dfs(i);
    }
    cout << cnt-1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    Input(), Solve();
    return 0;
}