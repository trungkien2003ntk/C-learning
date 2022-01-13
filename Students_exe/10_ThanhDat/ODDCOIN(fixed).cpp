#include <bits/stdc++.h>
using namespace std;

int main()
{
   // unsigned long long arr[16]={1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000,0};

    int q;
    int c;
    unsigned long long ans[1000];
    int cnt=0;
    unsigned long long x,t,o;
    unsigned long long min[1000];
    int cntmin=0;
    int dem=0;
    unsigned long long MIN;
    cin>>q;
    for(int i=0;i<q;i++)
    {
      unsigned long long   arr[16]={1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000,0};
        dem=0;
        c=0;
        cin>>x>>o;
        t=o;
        arr[15]=x;
        sort(arr, arr+16); 
        for(int k=15;k>=0;k--)
        { 
            while(t/arr[k]!=0)
            {
                    c++;
                t=t-arr[k];
            if(t==0)
                break;
            }
            if(k==0&&dem!=16)
            {
                dem++;
                k=15-dem; 
                min[cntmin]=c;
                cntmin++;
                if(k==0)
                    break;
                c=0; 
                t=o;     
            }
        }
        MIN=min[0];
        for(int y=1;y<cntmin;y++)
            if(min[y-1]>min[y])
                MIN=min[y];

        ans[cnt]=MIN;
        cnt++;
    }
    for(int x=0;x<cnt;x++)
        cout<<ans[x]<<endl;
}
