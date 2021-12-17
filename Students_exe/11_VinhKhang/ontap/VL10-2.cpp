#include <bits/stdc++.h>

using namespace std;

string n;
void nhap(){
	cin>>n;
}
void xuli(){
	cout << (n[0]=='-'?n.size()-1:n.size());
}
int main(){
	nhap();
	xuli();
	return 0;
}