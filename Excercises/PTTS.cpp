#include <iostream>
using namespace std;

int main(){
    unsigned long long n,dem;
    cin >> n;
    for(unsigned long long i = 2; i <= n; i++){
        if (n%i==0){   
            dem = 0;
            while(n % i == 0){
                dem++;
                n /= i;
            }
            cout << i <<" "<<dem<<endl;
            
        }
    }    
}
/*
#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
unsigned long long n;

bool Prime(unsigned long long x){
    int count=0;
    for (unsigned long long i=2; i<round(sqrt(x));i++){
        if (x%i ==0){
            count++;
        }
    }
    if (count != 0)
        return 0;
    else 
        return 1;
}

int count(unsigned long long div_num){
    int count_temp=0;
    while (n% div_num ==0){
        n/div_num;
        count_temp++;
    }
    return count_temp;
}

void PTTS(){
    cin>>n;
    for (unsigned long long i=2;i<=n;i++){
        if (n%i==0 && Prime(i)==1)
            cout<<i<<" "<<count(i)<<endl;
    }
}

int main(){
    PTTS();
    return 0;
}
*/