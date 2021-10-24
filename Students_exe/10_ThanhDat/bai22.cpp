#include <iostream>
using namespace std;

int mulu(int n){
    int tich=1;
    for(int x=1;x<=n/2;x++)
    {
        if(n%x==0)
            tich=tich*x;
    }
    return tich*n;
}
int main(){
    int n;
    cin>>n;
    cout<<mulu(n);
    return 0;
}