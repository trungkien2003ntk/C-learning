#include <bits/stdc++.h>
using namespace std;
string N;
string arr['zero'];
void nhap(){
	getline(cin,N);
}
void xuli(){
	for(int i=0;i<N.size();i++){
		if(N[i]==arr['zero'])
			cout << "ZERO";
	}
}
int main(){
	nhap();
	xuli();
	return 0;
}