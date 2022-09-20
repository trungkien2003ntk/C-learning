#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> total;

void nhap(){
	int tempt,tg=0;
	cin >> n;
	for (int i =1;i<=n;i++){
		cin >> tempt;
		tg += tempt;
		total.push_back(tg);
	}
}

void xuly(){
	int kq=0;
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
			if (total[i]==total[j]){
				kq = max(kq,j-i);
				break;
			}
	cout << kq;
}

int main(){
	nhap();
	xuly();
	return 0;
}