#include <iostream>
#include <cmath>
using namespace std;

int n;

void nhap(){
	cin >> n;
}

bool checknt(long long x){
	bool kq = true;
	if (x<2)
		kq = false;
	long long tempt = sqrt(x);
	for (long long i=2;i<=tempt;i++)
		if (x%i==0)
			kq = false;
	return kq;
}

void xuly(){
	long long res=0;
	for (int i = 2;i<n;i++)
		if (checknt(i) && checknt(n-i) && (i<=n-i))
			res++;
	cout << res;
}

int main(){
	nhap();
	xuly();
	return 0;
}