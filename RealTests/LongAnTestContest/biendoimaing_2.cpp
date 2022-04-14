#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long m,n,q;
vector<long long> a,x;
vector<pair<int,pair<int,int>>> datIn;

void nhap(){
	long long tempt;
	long long u,v,k;
	cin >> n >> m >> q;
	a.push_back(0);
	for (long long i=1;i<=n;i++){
		cin >> tempt;
		a.push_back(tempt);
	}
	
	for (long long i=1;i<=m;i++){
		cin >> u >> v >> k;
		datIn.push_back(make_pair(u,make_pair(v,k)));
	}
	sort(datIn.begin(),datIn.end());
	
	for (long long i=1;i<=q;i++){
		cin >> tempt;
		x.push_back(tempt);
	}
}

long long xuly(long long x){
	long long result;
	
}

int main(){
	nhap();
	xuat();
	return 0;
}