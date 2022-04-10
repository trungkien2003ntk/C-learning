//MINNUM

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str,temp="";
    cin>>str;
    long long minn=1000000;
    for(int x=0;x<str.size();x++)
    {  
        if(str[x]>='0'&&str[x]<='9')
        {
            temp+=str[x];
            if(x==str.size()-1)
            {
                long long a=stoi(temp);
                minn=min(a,minn);
            }

        }
        else
        {   if(temp!="")
            {
                long long a=stoi(temp);
                minn=min(a,minn);
            }
            temp="";
        }
    }
    cout<<minn;
}

//GOLDBACH

#include <bits/stdc++.h>
using namespace std;

int eratos[1000001]={0};

void dperatos()
{
	eratos[0]=eratos[1]=1;
	for(int x=2;x*x<=1000001;x++)
	{
		if(eratos[x]==0)
		{
			for(int i=x*x;i<=1000001;i=i+x)
				if(eratos[i]==0)
					eratos[i]=1;
		}
	}
}

int main()
{
    dperatos();
    int n;
    cin>>n;
    int res=0;
    for(int x=n/2;x>=1;x--)
    {
        if(eratos[x]==0&&eratos[n-x]==0)
            res++;
    }
    cout<<res;

}


//BIENDOIMANG

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n,m,q,u,v,k,qq,pos[1000000]={0},neg[1000000]={0};
    cin>>n>>m>>q;
    long long a[1000000],cnt[1000000]={0};
    for(int x=1;x<=n;x++) 
        cin>>a[x];
    for(int x=1;x<=m;x++)
    {
        cin>>u>>v>>k;
        cnt[u]+=k;cnt[v+1]-=k;      
    }
    for(int x=2;x<=n;x++)
        cnt[x]+=cnt[x-1];
    for(int x=1;x<=n;x++)
    {
        if(cnt[x]+a[x]>=0)
            pos[cnt[x]+a[x]]++;
        else
            neg[abs(cnt[x]+a[x])]++;
    }
    for(int x=1;x<=q;x++)
    {
        cin>>qq;
        if(qq>=0)
            cout<<pos[qq]<<" ";
        else
            cout<<neg[abs(qq)]<<" ";
    }

}
