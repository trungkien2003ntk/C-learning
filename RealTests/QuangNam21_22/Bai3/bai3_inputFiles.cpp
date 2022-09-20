#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int n;
vector<int> total;

void nhap(){
	int tempt,tg=0;
	ifstream f("bai3.inp");
	f >> n;
	for (int i =1;i<=n;i++){
		f >> tempt;
		tg += tempt;
		total.push_back(tg);
	}
	f.close();
}

void xuly(){
	int kq=0;
	// Xu ly co ban
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
			if (total[i]==total[j]){
				kq = max(kq,j-i);
				cout << kq << endl;
				break;
			}
	cout << kq;
}

int main(){
	nhap();
	xuly();
	return 0;
}