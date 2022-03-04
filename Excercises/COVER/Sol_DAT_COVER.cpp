#include <bits/stdc++.h>
#include <string>
using namespace std;

int m,n,k,minn=250000; bool stop=0;
string str[502];

void Input() 
{
  
    string temp;
    for(int x=1;x<=m;x++) {
        str[x]=str[x]+'2';
        cin>>temp;
        str[x]=str[x]+temp;
        

    }
}

void debugInput()
{
    for(int x=0;x<=m+1;x++)
        cout<<str[x]<<endl;
}

void xuly()
{
    int a,b;
    for(int j=1;j<=k;j++)
    {
        if(k%j==0)
        {
        a=j;b=k/j;
       // cout<<a<<" "<<b<<endl;
                for(int hang=1;hang<=m-a+1;hang++)
                    for(int cot=1;cot<=n-b+1;cot++)
                    {
                        int dem=0;
                        for(int x=hang;x<hang+a;x++)
                        {
                            for(int i=cot;i<cot+b;i++)
                            {
                                    if(str[x][i]=='1')
                                        dem++;
                            }      
                        }
                    if(dem<minn)   
                        minn=dem; 
                    }    
             }
            
         if(j==k && minn==250000)
            {cout<<-1;
             return ;}
    }
    cout<<minn;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>m>>n>>k;
    Input();
    //debugInput();
    xuly();
}