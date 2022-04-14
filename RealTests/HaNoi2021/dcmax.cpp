#include <bits/stdc++.h>
using namespace std;

int N,K;
vector<pair<long long,int>> datIn;

bool rule(pair<long long,long long> a, pair<long long, long long> b){
		if (a.first == b.first && a.second > b.second)
			return true;
		if (a.first < b.first)
			return true;
		return false;
}

int main(){
	cin >> N >> K;
	long long x,y;
	for (int i=1;i<=N;i++){
		cin >> x >> y;
		datIn.push_back(make_pair(x,1));
		datIn.push_back(make_pair(y,-1));
	}
	
	sort(datIn.begin(),datIn.end(),rule);
	
	long long temptSum=0,result = 0;
	for (int i=0;i<=datIn.size();i++){
		temptSum += datIn[i].second;
		if (temptSum == K)
			if (datIn[i].second == 1 && datIn[i+1].second == -1)
				result += datIn[i+1].first - datIn[i].first + 1;
			else if (datIn[i].second == -1 && datIn[i+1].second == 1)
				result += datIn[i+1].first - datIn[i].first - 1;
			else
				result += datIn[i+1].first - datIn[i].first;
	}
	cout << result;
	return 0;
}