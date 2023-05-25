#include <bits/stdc++.h>
using namespace std;

long long N,K,a[500001];

void nhap(){
	cin >> N >> K;
	for (int i=1;i<=N;i++)
		cin >> a[i];
}

void nhapFile(){
	ifstream f("input.045");
	f >> N >> K;
	for (int i=1;i<=N;i++)
		f >> a[i];
	f.close();
}
int main(){
	nhapFile();
	// Sparse Table - Cay nhi phan
	vector<vector<long long>> SpTm,SpTM;
	
	long long h = floor(log2(N));
	
	vector<long long> tempt;
	// Base case
	for (long long j=0;j<N;j++)
		tempt.push_back(a[j+1]);
	SpTm.push_back(tempt);
	SpTM.push_back(tempt);
	// iterative dynamic programming approach
	// (1<<i) là toán tử bit dịch 1 sang trái i bit tương đương với phép nhân cho 2^i
	// toán tử A<<n là phép dịch chuyển A sang trái n bit tương đương với phép nhân cho 2 mũ n. 
	for (long long i=1;i<=h;i++){
		vector<long long> tp;
		SpTm.push_back(tp);
		SpTM.push_back(tp);
		for (int j=0;j+(1<<i)<=N;j++){
			SpTm[i].push_back(min(SpTm[i-1][j], SpTm[i-1][j + (1<<(i-1))]));
			SpTM[i].push_back(max(SpTM[i-1][j], SpTM[i-1][j + (1<<(i-1))]));
		}
	}
	
	long long res = 0;
	for (long long i=0;i<=h;i++)
		for (long long j=0;j+(1<<i)<=N;j++)
			if (SpTM[i][j]-SpTm[i][j] <= K)
				res++;
	cout << res;
	
	return 0;
}