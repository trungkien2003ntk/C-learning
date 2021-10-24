#include <iostream>
using namespace std;

void minmax(int n){
    int j;
    int min=9;
    int max=0;
    while(n>0)
    {
       j=n%10;
       n=n/10;
       if(max<j)
        max=j;
       if(min>j)
        min=j; 
    }
    cout<<max<<" "<<min;
}
int main(){
    int n;
    cin>>n;
    minmax(n);
    return 0;
}