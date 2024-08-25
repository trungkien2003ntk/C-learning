#include <bits/stdc++.h>
using namespace std;

long long n;
int main()
{
    scanf("%lld", &n);
    cout << (((n & 1) || (n <= 2)) ? "NO" : "YES");
}