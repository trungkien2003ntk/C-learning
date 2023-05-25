#include <iostream>
using ll = long long;

using namespace std;

ll gcd(ll a,ll b){
	while (a!=b)
		if (a>b)
			a-=b;
		else
			b-=a;
	return a;
}

int main(){
	ll a,b,k;
	cin >> a >> b;
	ll ucln = gcd(a,b);
	k = a/ucln-1;
	ll res = b*k-a;
	cout << res;
	return 0;
}