#include <iostream>
#include <cmath>
using namespace std;

void sum(int n)
{
    for(int x=1;x<=n/2;x++)
    {
        if(n%x==0)
        {
            cout<<x<<" ";
        }
    }
    cout<<n;
}

int main(){
    int n;
    cin>>n;
    sum(n);
    return 0;
}