#include <iostream>
#include <set>

using namespace std;

int N;
long long K, total = 0;
set<pair<long long, long long>> datIn;

void nhap()
{
	cin >> N >> K;
	long long x, y;
	for (int i = 1; i <= N; i++)
	{
		cin >> x >> y;
		datIn.insert(make_pair(x, y));
	}
}

void nhapTho()
{
	N = 10;
	K = 59;
	datIn.insert(make_pair(31, 6));
	datIn.insert(make_pair(22, 5));
	datIn.insert(make_pair(2, 10));
	datIn.insert(make_pair(13, 3));
	datIn.insert(make_pair(24, 4));
	datIn.insert(make_pair(17,6));
	datIn.insert(make_pair(16,7));
	datIn.insert(make_pair(35,6));
	datIn.insert(make_pair(18,2));
	datIn.insert(make_pair(14,3));
}

void xuly()
{
	set<pair<long long,long long>>::iterator item=datIn.begin();
	long long result = 0, people = 0, tempt = item->first * item->second;
	while (result + tempt <= K)
	{
		result += tempt;
		people += item->second;
		item++;
		tempt = item->first * item->second;
	}
	cout << people + (K-result)/(item->first);
}

int main()
{
	nhapTho();
	xuly();
	return 0;
}