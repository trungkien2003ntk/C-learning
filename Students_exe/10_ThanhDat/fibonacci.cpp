#include <iostream>
#include <string>
using namespace std;

void Fobonacii(int n)
{   
    int arr[1000];
    int count=2;
    arr[0]=0;
    arr[1]=1;
    long long num;
    if(n>1)
    {
        for(int x=2;x<=n;x++) 
        {
            arr[x]=arr[x-1]+arr[x-2];
            num=arr[x];
        }
        cout<<num;
    }
    else
        cout<<arr[1];
}

int main()
{
    int n;
    cin>>n;
    Fobonacii(n);
    return 0;
}