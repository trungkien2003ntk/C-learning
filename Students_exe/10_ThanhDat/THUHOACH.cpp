#include <bits/stdc++.h>
using namespace std;

int main()
{
    int C,n;
    int a[22],res[200]={0},cnt=0;
    cin>>n>>C;
    for(int x=0;x<n;x++)
        cin>>a[x];
    sort(a,a+n);
    for(int x=0;x<n;x++)
    {
        int sum=C-a[x];
        if(sum>=0)
        {
            for(int i=n-1;i>=0;i--)
            {
                if(i!=x)
                    if(sum-a[i]>=0)
                        sum=sum-a[i];
                 if(i==0)
                     res[cnt++]=sum;
            }
        }   
    }
    int minn=500001;
    for(int i=0; i<cnt; i++)
        if(res[i]<minn)
            minn=res[i];
            if(C-minn<0)
                cout<<"0";
            else
    cout<<C-minn;
}
