// File Nop Test
#include<bits/stdc++.h>

using namespace std;

int n,ques;
vector<int> a,k,ProfitByDay;

void nhap(){
    cin >> n;
    int x;
    for (int i=0;i<n;i++){
        cin >> x;
        a.push_back(x);
	}
	cin >> ques;
	for (int i=1;i<=ques;i++){
		cin >> x;
		k.push_back(x);
	}
}

void xuly(){
	int temptMaxPrice = a[n-1];
	ProfitByDay.push_back(0);
	int j = 0;
	for (int i=n-2;i>=0;i--){
		temptMaxPrice = max(temptMaxPrice,a[i]);
		ProfitByDay.push_back(temptMaxPrice-a[i]+ProfitByDay[j]);
		j++;
	}
	reverse(ProfitByDay.begin(),ProfitByDay.end());
}

void xuat(){
	for (int i=0;i<ques;i++)
		cout << ProfitByDay[k[i]-1] << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    nhap();
    xuly();
    xuat();
    return 0;
}