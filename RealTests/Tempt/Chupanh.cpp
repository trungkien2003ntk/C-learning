#include <bits/stdc++.h>
using namespace std;

int N,K,a[500001];

int main(){
	cin >> N >> K;
	for (int i=1;i<=N;i++)
		cin >> a[i];
	// Sparse Table - Cay nhi phan
	vector<vector<int>> SpT;
	int Log2[N];
	
	int h = floor(log2(N));
	
	// Base case
	for (int j=0;j<N;j++){
		vector<int> tempt;
		tempt.push_back(a[j]);
		SpT.push_back(tempt);
	}
	
	// iterative dynamic programming approach
	// (1<<i) là toán tử bit dịch 1 sang trái i bit tương đương với phép nhân cho 2^i
	// toán tử A<<n là phép dịch chuyển A sang trái n bit tương đương với phép nhân cho 2 mũ n. 
	for (int i=1;i<=h;i++)
		for (int j=0;j+(1<<i)<=N;j++))
	
	return 0;
}