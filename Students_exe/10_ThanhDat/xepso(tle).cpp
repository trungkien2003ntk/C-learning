#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int check=0;
unsigned long long maxx,minn;
int T;
unsigned long long l,r,resmax[1001],resmin[1001];
int cnt=0;


int soque(int x)
{
    int que;
    if(x==0||x==6||x==9)
        que=6;
    if(x==1)
        que=2;
    if(x==2||x==3||x==5)
        que=5;
    if(x==4)
        que=4;
    if(x==7)
        que=3;
    if(x==8)
        que=7;
    return que;
}

void xuli()
{
    maxx=0;minn=1000000000;
    unsigned long long k;
    unsigned long long temp;
    unsigned long long sum1so;
    unsigned long long chieudail=to_string(l).length();
    unsigned long long limitl=1;
    for(int x=0;x<chieudail;x++)
        limitl=limitl*10;
    for(int i=l;i<=limitl;i++)
    {
       
        temp=i;
        sum1so=0;
        while(temp!=0)
        {
            k=temp%10;
            temp=temp/10;
            sum1so=sum1so+soque(k);
        }
        if(i==0)
            sum1so=6;
        if(minn>sum1so)
            minn=sum1so;
    }
    unsigned long long chieudair=to_string(r).length()-1;
    unsigned long long limitr=1;
    for(int x=0;x<chieudair;x++)
        limitr=limitr*10;
     for(int i=limitr;i<=r;i++)
    {
         check++;
        temp=i;
        sum1so=0;
        while(temp!=0)
        {
            k=temp%10;
            temp=temp/10;
            sum1so=sum1so+soque(k);
        }
        if(i==0)
            sum1so=6;
        if(sum1so>maxx)
            maxx=sum1so;
    }
            
    resmin[cnt]=minn;
    resmax[cnt]=maxx;
    cnt++;
    cout<<check<<endl;
}

int main()
{
    cin>>T;
    for(int x=0;x<T;x++)
    {
        cin>>l>>r;
        xuli();
    }
    for(int x=0;x<cnt;x++)
        cout<<resmin[x]<<" "<<resmax[x]<<endl;
}
