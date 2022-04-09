#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
long long K;
vector<pair<int,int>> datIn;
void nhap()
{
	cin >> N >> K;
	long long x, y;
	for (int i = 1; i <= N; i++)
	{
		cin >> x >> y;
		datIn.push_back(make_pair(x,y));
	}
	sort(datIn.begin(),datIn.end());
}

void nhapTho()
{
	N = 10;
	K = 59;
	datIn.push_back(make_pair(31,6));
	datIn.push_back(make_pair(22,5));
	datIn.push_back(make_pair(2,10));
	datIn.push_back(make_pair(13,3));
	datIn.push_back(make_pair(24,4));
	datIn.push_back(make_pair(17,6));
	datIn.push_back(make_pair(16,7));
	datIn.push_back(make_pair(35,6));
	datIn.push_back(make_pair(18,2));
	datIn.push_back(make_pair(14,3));
	sort(datIn.begin(),datIn.end());
}

void xuly(){
	long long result = 0,tempt,people = 0;
	int i = 0;
	tempt = datIn[i].first * datIn[i].second;
	while (result + tempt <=K){
		result += tempt;
		people += datIn[i].second;
		i++;
		tempt = datIn[i].first * datIn[i].second;
	}
	if (K == result)
		cout << people;
	else 
		cout << people + (K-result)/(datIn[i].first);
}

int main(){
	nhap();	
	xuly();
	return 0;
}