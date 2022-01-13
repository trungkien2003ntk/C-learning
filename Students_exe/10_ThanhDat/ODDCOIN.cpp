#include <bits/stdc++.h>
using namespace std;

int main()
{
   // unsigned long long arr[16]={1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000,0};

    int q;
    int c;
    int ans[100];
    int cnt=0;
    unsigned long long x,t,o;
    int prev;
    int dem=0;
    int stop=0;
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
                if(dem!=0)
                {
                    if(c>prev)
                    {
                         ans[cnt]=prev;
                        cnt++;
                        break;
                    }
                }
                prev=c;
                dem++;
                k=15-dem; 
                c=0; 
                t=o;     
            }
        }
  //      ans[cnt]=c;
  //      cnt++;
    }
    for(int x=0;x<cnt;x++)
        cout<<ans[x]<<endl;
}
