#include <bits/stdc++.h>
#include <string>
#define nmax 501

using namespace std;

int f[nmax][nmax];
long long m, n, k, res;
int rect(int r1, int c1, int r2, int c2) {
    return f[r2][c2] - f[r2][c1 - 1] - f[r1 - 1][c2] + f[r1 - 1][c1 - 1];
}
void minimize(long long &a, int b) {
    if (b < a)
        a = b;
}
void optimize(int r, int c) {
    for (int r1 = 1; r1 <= m - r + 1; r1++)
        for (int c1 = 1; c1 <= n - c + 1; c1++) minimize(res, rect(r1, c1, r1 + r - 1, c1 + c - 1));
}
int main() {
    char s[nmax + 5];
    memset(f, 0, sizeof f);
//    scanf("%d%d%d\n", &m, &n, &k);
	ifstream fl("sub3_6.in");
    fl >> m >> n >> k;
    for (int i = 1; i <= m; i++) {
//        scanf("%s", s + 1);
		fl >> s+1;
        for (int j = 1; j <= n; j++) f[i][j] = (s[j] == '1') + f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
    }
	fl.close();
	
//	cout << m << " " << n << " " << k << endl;
	
    res = k + 1;
    for (int i = 1; i * i <= k; i++)
        if (k % i == 0) {
            int j = k / i;
            if (i <= m && j <= n)
                optimize(i, j);
            if (j <= m && i <= n && i != j)
                optimize(j, i);
        }
    if (res==k+1) cout << -1;
    else cout << res;
//    printf("%d", res == k + 1 ? -1 : res);
}
