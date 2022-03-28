#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>

int arr[201];
int N;
bool check[201];
int sumcheck[201],cnt=1,res=0;

using namespace std;

void Input()
{
    cin>>N;
    for(int i=1;i<=N;i++)
        cin>>arr[i];
}

void output()
{
    int sum=0;
    for(int x=1;x<=N;x++)
        if(check[x]!=0)
        {
            sum+=arr[x];
           // cout<<sum<<endl;
        }
    for(int x=0;x<cnt;x++)
    {
        if(sum==sumcheck[x])
            break;
        if(x==cnt-1)
        {
            sumcheck[cnt++]=sum;
            res++;
        }
    }
}

void recursion(int u)
{
    if(u==N+1)
    {  
       return output();;
    }
    check[u]=0;
    recursion(u+1);
    check[u]=1;
    recursion(u+1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    Input();
    recursion(1);
    cout<<res;
    return 0;
}

