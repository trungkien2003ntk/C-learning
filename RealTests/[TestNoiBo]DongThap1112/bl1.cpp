// Thoi gian gioi han la 3s
#include <bits/stdc++.h>
#include <string>

using namespace std;

typedef long long ll;

ll n,k,p;
string s="";
ll counter=0;

void nhap(){
	ifstream f("tong.inp");
	f >> n >> k >> p;
	f.close();
}

void khoiTao(){
	for (int i=1;i<=k/9;i++)
		s += 9 + '0';
	char tempt = (k % 9) + '0';
	s = tempt + s;
	cout << s;
}

void xuly(ll &counter,ll pos){
	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	nhap();
	khoiTao();
	
	return 0;
}