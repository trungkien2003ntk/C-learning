#include <iostream>

using namespace std;

int main(){
	int N;
	long long K;
	long long counter = 0;
	
	cin >> N >> K;
	long long P[N],C[N];
	for (int i=1;i<=N;i++)
		cin >> P[i] >> C[i];
	
	for (int i=1;i<N;i++)
		for (int j=i+1;j<=N;j++)
			if (P[i] > P[j]){
				swap(P[i],P[j]);
				swap(C[i],C[j]);
			}
			
	int i = 1;
	long long tempt = P[1]*C[1];
	while (K>0){
		if (tempt<=K){
			K -= tempt;
			counter += C[i];
			i++;
			tempt = P[i]*C[i];
		}
		else{
			counter += K/P[i];
			break;
		}
	}
	
	cout << counter;
	
	return 0;
}