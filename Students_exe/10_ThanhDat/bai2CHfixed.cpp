#include <bits/stdc++.h>
using namespace std;
int N,arr[10000],res[10000],cnt=0,kq=1;
bool check[10000]={0};

void show()
{
    cnt=0;
    for(int i=1;i<=N;i++)
        if(check[i]==1)
            res[cnt++]=arr[i];   
}

void Try(int i,int cursum)
{
    if(cursum>kq)
    {
        kq=cursum;
        show();
    }
    for(int x=i;x<=N;x++)
    {
        if(check[x]==0)
        {
            bool sinh=1;
            for(int j=1;j<x;j++)
                if(arr[x]%arr[j]!=0&&check[j]==1)
                {
                    sinh=0;
                    break;
                }
            if(sinh!=0)
            {
                check[x]=1;
                Try(x,cursum+1);
                check[x]=0;
            }
        }
    }
}

int main()
{
    cin>>N;
    for(int i=1;i<=N;i++)
        cin>>arr[i];
    Try(1,0);
    cout<<kq<<endl;
    for(int x=0;x<cnt;x++)
        cout<<res[x]<<" ";
}
