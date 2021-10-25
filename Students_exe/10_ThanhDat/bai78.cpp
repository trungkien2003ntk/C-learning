#include <iostream>
#include <cmath>
using namespace std;

void uoc(int n)
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
    uoc(n);
    return 0;
}