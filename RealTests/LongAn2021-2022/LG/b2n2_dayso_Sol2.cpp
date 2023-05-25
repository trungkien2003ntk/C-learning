#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

long long N,M,S,mi;
vector<long long> A,B;

void Nhap(){
	ifstream f;
	f.open("dayso.inp");
	f >> N >> M >> S;
	mi = N;
	long long x;
	for (int i=1;i<=M;i++){
		f >> x;
		mi = min(mi,x); 
		A.push_back(x);
	}	
	f.close();
	sort(A.begin(),A.end());
}

void NhapInline(){
	cin >> N >> M >> S;
	mi = N;
	long long x;
	for (int i=1;i<=M;i++){
		cin >> x;
		mi = min(mi,x);
		A.push_back(x);
	}
	sort(A.begin(),A.end());
}


void xuly(){
	if (A[0]==1)
		B.push_back(0);
	else if (A[0]-M > A[0]-1)
		B.push_back(A[0]-1);
	else
		B.push_back(A[0]-M);
		
	for (int i=1;i<A.size();i++)
		B.push_back(A[i]-A[i-1]-1);	
	for (int i=0;i<B.size();i++)
		B[i+1] += B[i];
	
	if (A[A.size()-1]==N)
		B.push_back(0);
	else if (N-A[A.size()-1]>S)
		B.push_back(S);
	else 
		B.push_back(N-A[A.size()-1]);
	
	for (int i=0;i<B.size();i++)
		cout << B[i] << " ";
}

void xuat(long long x){
	cout << x;
}



int main(){
	Nhap();
//	NhapInline();
	xuly();
}