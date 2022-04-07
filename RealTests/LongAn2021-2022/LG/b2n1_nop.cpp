#include <iostream>

using namespace std;

int N;
long long K;
long long P[10002],C[10002];
long long counter = 0;

void nhap(){
	cin >> N >> K;
	for (int i=1;i<=N;i++)
		cin >> P[i] >> C[i];	
}

void khoiTao(){
	for (int i=1;i<N;i++)
		for (int j=i+1;j<=N;j++)
			if (P[i] > P[j]){
				swap(P[i],P[j]);
				swap(C[i],C[j]);
			}
}

void xuly(){
	int i = 1;
	while (K>0){
		if (P[i]*C[i]<K){
			K -= P[i]*C[i];
			counter += C[i];
			i++;
		}
		else if (P[i]*C[i]==K){
			counter += C[i];
			break;
		}
		else {
			counter += K/P[i];
			break;
		}
	}	
}

void xuat(){
	xuly();
	cout << counter;
}

int main(){
	nhap();
	khoiTao();
	xuat();
	return 0;
}