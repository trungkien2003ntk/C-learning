#include <iostream>
using namespace std;

int sum(int n){
    int sum_n=0;
    for(int x=0;x<=n;x++)
        sum_n=sum_n+x*x;
    return sum_n;
}

int main(){
    int n;
    cin>>n;
    cout<<sum(n);
    return 0;
}