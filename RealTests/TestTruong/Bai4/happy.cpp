#include <iostream>

#define ll long long
using namespace std;

ll n, total = 0,totalMul=0;

void nhapvaxuly(){
    cin >> n;
    ll tempt;
    cin >> tempt;
    total += tempt;
	for (int i=1;i<n;i++){
		cin >> tempt;
		totalMul += tempt * total;
		while (totalMul >= 1000000007)
        	totalMul %= 1000000007;
		total += tempt;
	}
}

void xuat(){
    cout << totalMul;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    nhapvaxuly();
    xuat();
    return 0;
}