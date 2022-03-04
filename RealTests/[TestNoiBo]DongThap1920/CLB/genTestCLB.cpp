// Get test Case
#include <bits/stdc++.h>
#include <string>
#include <random>

using namespace std;

void nhapnxuly(){
	long long n,minauto, maxauto,kq,kq_return;
	unordered_set <long long> dat_set;
	string filename;
	cin >> n;
	cin >> kq;
	cin >> filename;
	
	random_device rd;
	mt19937 gen(rd());
	minauto = kq+5;
	maxauto = minauto + n + 1000000;
	
	uniform_int_distribution<> distr(minauto,maxauto);
	
	ofstream f(filename);
	f << n << endl;
	for (long long i=1;i<=kq-1;i++)
		dat_set.insert(i);
	while (dat_set.size() < n)
		dat_set.insert(distr(gen));	
	
	unordered_set<long long>::iterator it;
	for (it=dat_set.begin();it!=dat_set.end();it++)
		f << *it << " ";
	f.close();
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	nhapnxuly();
	return 0;
}