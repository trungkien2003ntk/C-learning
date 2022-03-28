#include <bits/stdc++.h>
using namespace std;
int arr[100000],res[100000],savedarr[1000000];
int main()
{
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
        savedarr[i]=arr[i];
    }
    sort(arr,arr+N);
    int maxx=-1,savepos;
    res[0]=1;
    for(int i=1;i<N;i++)
    {
        int bienchay=i-1;
        while(arr[i]%arr[bienchay]!=0)
        {
            bienchay--;
            if(bienchay==-1)
                break;
        }

        if(bienchay!=-1)
            res[i]=res[bienchay]+1;
        else
            res[i]=1;

        if(maxx<res[i])
        {
            savepos=i;
            maxx=res[i];
        }
    }
    if(maxx!=1)
    {
     cout<<maxx<<endl;
        for(int x=0;x<N;x++)
            if(arr[savepos]%savedarr[x]==0)
                cout<<savedarr[x]<<" ";
    }
    else
        cout<<"-1";
}
