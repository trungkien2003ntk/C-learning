#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
unordered_map<int,int> dic;
vector<int> price;
int N;
long long K;

void nhap()
{
	cin >> N >> K;
	long long x, y;
	for (int i = 1; i <= N; i++)
	{
		cin >> x >> y;
		price.push_back(x);
		dic[x]=y;
	}
	sort(price.begin(),price.end());
}

void nhapTho()
{
	N = 10;
	K = 59;
	price = {31,22,2,13,24,17,16,35,18,14};
	dic[31]=6;
	dic[22]=5;
	dic[2]=10;
	dic[13]=3;
	dic[24]=4;
	dic[17]=6;
	dic[16]=7;
	dic[35]=6;
	dic[18]=2;
	dic[14]=3;
	sort(price.begin(),price.end());
}

void xuly(){
	long long total=0,sis=0;
	int i = 0;
	long long temptMul = price[0]*dic[price[0]];
	while (total + temptMul <= K){
		sis += dic[price[i]];
		total += temptMul;
		i++;
		temptMul = price[i]*dic[price[i]];
	}
	if (K!=total)
		cout << sis + (K-total)/price[i];
	else
		cout << sis;
}

int main(){
	nhapTho();
	xuly();
	return 0;
}