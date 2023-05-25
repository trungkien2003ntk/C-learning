#include <iostream>

using namespace std;
long long n;
double uocso(long long n){
	float t=0;
	for(int i=1;i<=n;i++){
		if(n%i==0)
			t+=i;
	}
	return t;
}
float m;
int t;
int main(){
	
	cin >> n;
	for(long long i=1;i<=100000000000000000;i++){
		if(uocso(n)/n == uocso(i)/i && i> n){
			cout << i;
			break;
		}
	}
}
