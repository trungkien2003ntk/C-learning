#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[1000000];
    int arrss[1000000];
    int carrss=0;
    for(int x=1;x<=n;x++)
        cin>>arr[x];
    int c=1;
    long long sum1=0;
    long long sum2=0;
    int ss;
    for(int k=1;k<=n;k++)
    {
        ss=0;
        sum1=0;
        sum2=0;
        for(int x=1;x<=c;x++)
            sum1=sum1+arr[x];
        for(int i=n;i>c;i--)
            sum2=sum2+arr[i];
        ss=abs(sum1-sum2);
        arrss[carrss]=ss;
        carrss++;
        c++;
    }
    int min=arrss[0];
    for(int x=1;x<carrss;x++)   
    {
        if(arrss[x]<min)
            min=arrss[x];
    }
    cout<<min;
    return 0;
}
