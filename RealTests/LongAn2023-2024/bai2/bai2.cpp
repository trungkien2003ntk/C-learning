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
int n;
long long tempt;

map<long long, vector<int>> ipStu;
vector<pair<long long, pair<long long, int>>> res;

bool compare(pair<long long, pair<long long, int>> x, pair<long long, pair<long long, int>> y)
{
    if (x.first > y.first)
        return true;
    else if (x.first == y.first && x.second.first < y.second.first)
        return true;
    else
        return false;
}

int main()
{
    fast_io;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tempt;
        ipStu[tempt].push_back(i);
    }

    for (auto it : ipStu)
        res.push_back({it.second[it.second.size() - 1] - it.second[0], {it.second[0], it.first}});

    sort(res.begin(), res.end(), compare);

    cout << res[0].second.second << "\n"
         << res[0].first;
    // getchar();
}