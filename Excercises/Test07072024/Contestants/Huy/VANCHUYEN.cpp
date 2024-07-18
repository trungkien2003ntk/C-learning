#include <bits/stdc++.h>
using namespace std;
long long n,m,mm,s,a,b,t,w,Max=-1, cnt[100001];

vector <pair<int,int>> v[100001];

void dijkstra(int start) 
{
    for(int i = 0; i < 100001; i++) 
	{
        cnt[i] = 1e9;
    }
    cnt[start] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, start});

    while (!pq.empty())
	{
        int u = pq.top().second; 
        long long dist = pq.top().first; 
        pq.pop();

        if (dist > cnt[u]) continue; 

        for (auto edge : v[u]) 
		{
            int v = edge.first;
            int weight = edge.second;

            if (cnt[u] + weight < cnt[v]) 
			{
                cnt[v] = cnt[u] + weight;
                pq.push({cnt[v], v}); 
            }
        }
    }
}


long long res;
int main()
{
    freopen("VANCHUYEN.INP","r",stdin);
    freopen("VANCHUYEN.OUT","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> s >> t;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> w;
		v[a].push_back({b, w});
		v[b].push_back({a, w});	
    }

    dijkstra(s);
    cout << cnt[t];
}
