#include <iostream>

using namespace std;
long long k;

void nhap(){
	cin >> k;
}

void xuly(){
	long long U=150,D=150;
	long long p,q,new_d,new_u,remainder,s, total;
	p=k/5;	
	q=k%5;
	new_u = 30*(p+1);
	s = (2*U+(p-1)*D)*p/2;
	remainder = new_u * q;
	total = s + remainder;
	cout << total;
}

int main(){
	nhap();
	xuly();
	return 0;
}