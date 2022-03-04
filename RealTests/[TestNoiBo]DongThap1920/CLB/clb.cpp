#include <bits/stdc++.h>
#include <set>

using namespace std;
typedef long long ll;

ll n;
set<ll> dat_inp;
void xuat(ll ans);

void nhap(){
	ll tempt;
	ifstream f("clb9.inp");
	f >> n;
	while (!f.eof()){
		f >> tempt;
		dat_inp.insert(tempt);
	}
	f.close();
}

void xuly(){
	ll kq;
	set<ll>::iterator it1,it2;
	for (it1 = dat_inp.begin(),it2=++dat_inp.begin();it1!=dat_inp.end(),it2!=dat_inp.end();it1++,it2++)
		if (*it1 < *it2-1){
			kq = *it1;
			break;
		}
	if (it1 != dat_inp.end())
		xuat(*it1+1);
	else
		xuat(++kq);
}

void xuat(ll ans){
	ofstream f("clb.oup");
	f << ans;
	f.close();
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	nhap();
	xuly();
	return 0;
}