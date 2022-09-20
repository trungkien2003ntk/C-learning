// File Nop Test
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int n,ques;
vector<int> a,maxProfit,bP,k,ProfitByDay;
list<int> bestPaid;

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
	// Tinh Best Paid trong tuong lai cua gia tung ngay
	bestPaid.push_front(n-1);
    int tempt = n-1;
    for (int i=n-2;i>=0;i--)
    	if (a[i]>a[tempt]){
    		bestPaid.push_front(i);
    		tempt = i;
		}
    	else
    		bestPaid.push_front(tempt);
    // Chuyen bestPaid sang vector
    for (int i =0;i<n;i++){
    	bP.push_back(bestPaid.front());
    	bestPaid.pop_front();
	}
    // Tinh max Profit tung ngay
    for (int i=0;i<n;i++)
    	maxProfit.push_back(a[bP[i]]-a[i]);
    	
    ProfitByDay.push_back(maxProfit[0]);
    for (int i=1;i<n;i++)
    	ProfitByDay.push_back(maxProfit[i]+ProfitByDay[i-1]);
}

void xuat(){
	for (int i=0;i<ques;i++)
		if (k[i]-1 == 0)
			cout << ProfitByDay[n-1] << endl;
		else
			cout << ProfitByDay[n-1]-ProfitByDay[k[i]-1] << endl;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    nhap();
    xuly();
    xuat();
    return 0;
}