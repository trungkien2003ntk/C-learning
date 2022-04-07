#include <iostream>
#include <fstream>

using namespace std;

long long N,K;
long long P[10000],C[10000];

void nhap(){
	ifstream f;
	f.open("socola.inp");
	f >> N >> K;
	for (int i=1;i<=N;i++)
		f >> P[i] >> C[i];
	f.close();		
}

void khoiTao(){
	for (int i=1;i<N;i++)
		for (int j=i+1;j<=N;j++)
			if (P[i] > P[j]){
				swap(P[i],P[j]);
				swap(C[i],C[j]);
			}
}

long long xuly(){
	int i = 1;
	long long counter = 0;
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
		else if (P[i]*C[i]>K){
			counter += K/P[i];
			break;
		}
	}	
	return counter;
}

void xuat(){
	cout << xuly();
}

int main(){
	nhap();
	khoiTao();
	xuat();
	return 0;
}