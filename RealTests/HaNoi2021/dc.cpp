#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;

int N,K;
vector<pair<long long,long long>> datIn;
long long fron=1e18,las=1,counter = 0;
void nhap(){
	ifstream f("dc.inp");
	f >> N >> K;
	long long a,b;
	for (int i=1;i<=N;i++){
		f >> a >> b;
		fron = min(fron,a);
		las = max(b,las);
		datIn.push_back(make_pair(a,b));
	}
	f.close();
	
	sort(datIn.begin(),datIn.end());
}

void xuly(){
	vector<pair<long long,long long>> react;
	for (int i=fron;i<=las;i++){
		for (int j = 0;j <= datIn.size();j++)
			if (datIn[j].first <= i && datIn[j].second >=i)
				react.push_back(datIn[j]);
		for (int j =0;j<react.size();j++)
			if (react[j].first > i || react[j].second < i)
				react.erase(react.begin()+j);
		if (K==react.size())
			counter++;
		react.clear();
	}
}

void xuat(){
	cout << counter;
	ofstream f("dc.oup");
	f << counter;
	f.close();
}

int main(){
	nhap();
	xuly();
	xuat();
	return 0;
}