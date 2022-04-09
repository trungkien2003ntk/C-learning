#include <iostream>
#include <vector>
using namespace std;

long long m,n,q;
vector<long long> a,x;

void nhap();
void biendoi();

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
		for (long long i=u;i<=v;i++)
			a[i] += k;
	}
	
	for (long long i=1;i<=q;i++){
		cin >> tempt;
		x.push_back(tempt);
	}
}

void xuly(){
	long long result,res[q];
	for (long long i=0;i<q;i++){
		result = 0;
		for (long long j =1 ;j<=n;j++)
			if (a[j]==x[i])
				result++;
		res[i] = result;
	}
	for (long long i=0;i<q;i++)
		cout << res[i] << ' ';
}

int main(){
	nhap();
	xuly();
	return 0;
}