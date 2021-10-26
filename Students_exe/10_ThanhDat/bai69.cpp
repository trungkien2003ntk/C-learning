#include <iostream>
#include <cmath>
using namespace std;

int sum(int n,int x)
{
    int Sum=0;
    for(int so_n=1;so_n<n;so_n++)
    {
        Sum+=(pow(-1,so_n)*pow(x,(2*so_n)+1));
    }
    return Sum+x;
}

int main(){
    int n;
    int x;
    cin>>n>>x;
    cout<<sum(n,x);
    return 0;
}