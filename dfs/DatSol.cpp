#include <bits/stdc++.h>

#define X first
#define Y second
using namespace std;


vector<pair<int, int>> a[100000];
long long d[100000],way[100000];
int n,m;

void dijkstra(int st)
{
    priority_queue<pair<int, int>,vector<pair<int, int>>, greater <pair<int, int>>> q;
    for(int i=1;i<=n;i++)
        d[i]=1e9+7,way[i]=1;
    d[st]=0;
    way[st]=1;
    q.push({0,st});
    while(!q.empty())
    {
        int u=q.top().Y;
        int du=q.top().X;
        q.pop();

        if(du!=d[u]) continue;
        for(auto i:a[u])
        {
            int v=i.Y;
            int dv=i.X;
            if(d[v]==du+dv)
                way[v]+=way[u];
            if(d[v]>du+dv)
            {
                way[v]=way[u];
                d[v]=du+dv;
                q.push({d[v],v});
                
            }
        }
    }
}

int main(int argc, char** argv)
{
    freopen("GIAOTHONG.inp","r",stdin);
    freopen("GIAOTHONG.out","w",stdout);
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        a[u].push_back({w,v});
        a[v].push_back({w,u});
    }
    dijkstra(1);
    cout<<d[n]<<" "<<way[n];
    return 0;
}