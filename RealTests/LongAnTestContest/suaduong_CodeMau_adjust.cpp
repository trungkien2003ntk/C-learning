#include <bits/stdc++.h>

using namespace std;

int n, m;
const int N = 2e5+4;
vector<int> road[N];
bool passed[N];

void Input() {
    cin >> n >> m;
    for (int i=1;i<=m;++i) {
        int u, v; cin >> u >> v;
    	road[u].push_back(v);
        road[v].push_back(u);
    }
}
//De quy
void dfs(int u) {
    passed[u] = true;
    for(int v : road[u]) if (!passed[v]) {
        dfs(v);
    }
}

void Solve() {
	memset(passed, 0, sizeof passed);
    int cnt = 0;
    for (int i=1;i<=n;i++) if (!passed[i]) {
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