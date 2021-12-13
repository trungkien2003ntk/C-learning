#include <bits/stdc++.h>

using namespace std;
int a,b,x,y;
void nhap()
{
	cin>>a>>b;
	cin>>x>>y;
}
void xuli(){
	int tong1=0,tong2=0;
	for(int i=a;i<=b;i++){
		if(i==sqrt(i))
			tong1++;
	}
	for(int i=x;i<=y;i++){
		if(i%i==0&&i%1==0)
			tong2++;
	}
	cout << tong1 << endl;
	cout << tong2;
}
int main(){
	nhap();
	xuli();
	return 0;
}