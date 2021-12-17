#include <bits/stdc++.h>

using namespace std;
long long L,R,M;


void nhap(){
	ifstream f;
	f.open("BAI1.INP");
	f>>L>>R;
	f.close();
	
//	cin>>L>>R;
}

void xuli(){
	long long Sum=(R+L)*(R-L+1)/2;   //L+(L+1)+(L+2)+...+(L+n) = ((L+n)+L) * N /2;
	long long SumHalf = Sum/2;
	long long SumTemp = Sum;
	long long SumLost=0;
	long long pos;
//	cout<<Sum<<' '<<SumHalf<<endl;
	for (long long i = R; Sum>SumHalf ; i -- ){
		SumTemp = Sum;
		SumLost +=i;
		Sum -=i;
		pos = i;
	}
	long long SumTempLost = SumLost-pos;
	//cout<<SumTemp<<' '<<SumTempLost<<' '<<Sum<<' '<<SumLost<<' '<<pos<<endl;
	if (abs(SumTempLost - SumTemp) < abs(SumLost - Sum))
		M = pos;
	else
		M = pos-1;
}

void xuat(){
	ofstream f;
	f.open("BAI1.OUT");
	f<<M;
	f.close();
//	cout<<M;
}

int main(){
	nhap();
	xuli();
	xuat();
	return 0;
}