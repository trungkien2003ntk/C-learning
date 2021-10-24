#include <iostream>
#include <cmath>
using namespace std;

int sum(int n)
{
    int Sum=(n * (n+1))/2;
    return Sum;
}

int main(){
    int n;
    cin>>n;
    cout<<sum(n);
    return 0;
}