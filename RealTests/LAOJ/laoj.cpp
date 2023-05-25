// Cap nhat nghich the https://claoj.edu.vn/problem/updateinv
#include <iostream>
#include <vector>

using namespace std;

int n,q,a[10001];
vector<pair<int,int>> queries;

void nhap(){
	cin >> n >> q;
	for (int i=0;i<n;i++)
		cin >> a[i];
	int x,y;
	for (int i=0;i<q;i++){
		cin >> x >> y;
		queries.push_back(make_pair(x,y));
	}
}

int main(){
	nhap();
	return 0;
}