#include <bits/stdc++.h>
using namespace std;

 long long l, r;

void nhap();
long long sumlr( long long x,  long long y);
void xuly();
long long choose( long long x);
void xuat( long long x);
long long tuyetdoi( long long x);
// Chuong trinh nhap
void nhap() {
	ifstream f;
	f.open("bai1.inp");
	f >> l >> r;
	f.close();
}

// Tinh tong cac so tu x den y 
long long sumlr(long long x,  long long y) {
	return ((x + y)*(y - x + 1) / 2);
}

// Chon chi so xuat ra 
long long choose( long long x){
	SumTruoc1 = sumlr(l,x-1);
	SumSau1 = sumlr(x,r);
	ChenhLech1 = abs(SumTruoc1 - SumSau1);
	
	SumTruoc2 = sumlr(l,x);
	SumSau2 = sumlr(x+1,r);
	ChenhLech2 = abs(SumTruoc2 - SumSau2);
	
	if ( ChenhLech1 > ChenhLech2 )
		return x;
	return x-1;
}

// Chuong trinh xu ly
void xuly() {
	// Luu midsum = 1/2 tong tu l den r
	 long long midsum = sumlr(l, r)/2;
	 long long cs = r;
	while (sumlr(cs, r) < midsum)
		cs--;
	xuat(choose(cs));
}

// Chuong trinh xuat
void xuat(long long x){
	ofstream f;
	f.open("bai1.oup");
	f << x;
	f.close();
}
int main() {
	nhap();
	xuly();
	return 0;
}