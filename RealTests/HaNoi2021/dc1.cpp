#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;

int N,K;
vector<pair<long long,long long>> datIn;
long long fron=1e18,las=1,res=0,takenLast=1;
pair<long long,long long> empty=make_pair(0,-1);
vector<long long> saveResult;
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
	for (int i=1;i<=N;i++){
		saveResult.push_back(0);
		currPosResult.push_back(0);
	}
}

pair<long long,long long> intersec(pair<long long,long long> x, pair<long long, long long> y){
	long long xcoor=max(x.first,y.first), ycoor=min(x.second,y.second);
	if (xcoor<=ycoor)
		return make_pair(xcoor,ycoor);
	else
		return make_pair(0,-1);
}

bool mergeAble(pair<long long, long long> x, pair<long long, long long> y){
	if (x.second <= y.first || x.first >= y.second)
		return False;
	return True;
}

pair<long long, long long> merge(pair<long long, long long> x, pair<long long, long long> y){
	long long fi,la;
	fi = min(x.first,y.first);
	la = max(x.second,y.second);
	return make_pair(fi,la);	
}

void xuly(){
	
}

void xuat(){
	cout << res;
	ofstream f("dc.oup");
	f << res;
	f.close();
}

int main(){
	nhap();
	xuly();
	xuat();
	return 0;
}