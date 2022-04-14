#include <iostream>
#include <vector>

const int N = 1000000;
using namespace std;

int counter = 0;
vector<bool> tracker;
vector<int> datRaw[N];

void pass(int x){
	tracker[x]=1;
	for (int it = 0;it<datRaw[x].size();it++)
		if (!tracker[datRaw[x][it]])
			pass(datRaw[x][it]);
}

int main(){
	int n,m;
	int x,y;
	cin >> n >> m;

	for (int i=1;i<=m;i++){
		cin >> x >> y;
		datRaw[x].push_back(y);
		datRaw[y].push_back(x);
	}
	
	for (int i=1;i<=n;i++)
		if (!tracker[i]){
			counter++;
			pass(i);
		}
	cout << counter-1;
	return 0;
}