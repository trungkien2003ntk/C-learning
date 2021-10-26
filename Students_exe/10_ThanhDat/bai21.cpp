#include <iostream>
using namespace std;

int sumu(int n){
    int tong=0;
    for(int x=1;x<=n/2;x++)
    {
        if(n%x==0)
            tong=tong+x;
    }
    return tong+n;
}
int main(){
    int n;
    cin>>n;
    cout<<sumu(n);
    return 0;
}