#include <iostream>
#include <vector>
#include <fstream>
#define ll long long
using namespace std;

vector <pair<ll,ll> >  u;
ll K,N,a,b;
void nhap()
{
    ifstream f; f.open("DC.INP");
    f>>N>>K;
    for(int i=1; i<=N; i++)
    {
        f>>a>>b;
        u.push_back(make_pair(a,0));
        u.push_back(make_pair(b,1));
    }
}

void xuat(ll a)
{
    ofstream f; f.open("DC.OUT");
    f<<a;
    f.close();
}


void sapxep()
{
    sort(u.begin(),u.end());
}

void xuly()
{
    ll sum=0,res=0;
    for(int i=0; i<N*2; i++)
    {
        if(u[i].second==0)
            sum++;
        else
            sum--;

        if(sum==K)
        {
            if(u[i].second==0&&u[i+1].second==1)
            res+=u[i+1].first-(u[i].first)+1;
            else
                if((u[i].second==1&&u[i+1].second==0))
                  res+=u[i+1].first-(u[i].first+1);  
            else
            res+=u[i+1].first-u[i].first;
        }
    }
    xuat(res);
}

int main()
{
    nhap();
    sapxep();
    xuly();
}