#include <iostream>
using namespace std;

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

int main()
{   
    int k;
    int a,b;
    cin>>a;
    cin>>b;
    int sum=0;
    for(int x=a;x<=b;x++)
    {   
        int temp=x;
        int sum1so=0;
        while(temp>0)
        {
            k=temp%10;
            temp=temp/10;
            sum1so=sum1so+soque(k);
        }
        if(x==0)
            sum1so=6;
        sum=sum+sum1so;
    }
    cout<<sum;
    return 0;
}
