#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
double x;
int res = 1;
	
void nhap(){
	ifstream f("tbs.inp");
	for (int i=1;i<=4;i++){
		f >> x;
		if (x!=0) x = x/abs(x);
		res *=x;
	}
	f.close();
}

void xuat(){
	ofstream f("tbs.out");
	f << res;
	f.close();
}
int main(){
	nhap();
	xuat();
	return 0;
}