#include <iostream>
#include <set>
#include <vector>
using namespace std;

int N;
long long K;
set<pair<long long,long long>> datIn;
vector<pair<long long,long long>> datCooked;
void nhap()
{
	cin >> N >> K;
	long long x, y;
	for (int i = 1; i <= N; i++)
	{
		cin >> x >> y;
		datIn.insert(make_pair(x, y));
	}
	copy(datIn.begin(),datIn.end(),datCooked.begin());
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
	copy(datIn.begin(),datIn.end(),datCooked.begin());
}

void xuly(){
	set<pair<long long,long long>>::iterator item=datIn.begin();
	long long p,c,t;
	long long result=0;
	while (K>0){
		p=item->first;
		c=item->second;
		t=p*c;
		if (t<K){
			K -= t;
			result += c;
			item++;
		}
		else if (t==K){
			result += c;
			break;
		}
		else {
			result += K/p;
			break;
		}	
	}
	cout << result;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	nhapTho();
	xuly();
	return 0;
}