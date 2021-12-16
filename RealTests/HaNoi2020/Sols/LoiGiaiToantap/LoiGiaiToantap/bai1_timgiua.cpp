#include <bits/stdc++.h>
#include <fstream>
using namespace std;

unsigned long long l, r;

void nhap();
unsigned long long sumlr(unsigned long long x, unsigned long long y);
void xuly();
int choose(unsigned long long x);
void xuat(unsigned long long x);
unsigned long long tuyetdoi(unsigned long long x);
// Chuong trinh nhap
void nhap() {
	ifstream f;
	f.open("bai1.inp");
	f >> l >> r;
	f.close();
}

// Tinh tong cac so tu x den y 
unsigned long long sumlr(unsigned long long x, unsigned long long y) {
	return ((x + y)*(y - x + 1) / 2);
}

unsigned long long tuyetdoi(unsigned long long x){
	if (x>0)
		return x;
	return -x;
}

// Chon chi so xuat ra 
int choose(unsigned long long x){
	if (tuyetdoi(sumlr(l,x-1)-sumlr(x,r))>tuyetdoi(sumlr(l,x)-sumlr(x+1,r)))
		return x;
	return x-1;
}

// Chuong trinh xuat
void xuat(int x){
	ofstream f;
	f.open("bai1.oup");
	f << x;
	f.close();
}

// Chuong trinh xu ly
void xuly() {
	// Luu midsum = 1/2 tong tu l den r
	unsigned long long midsum = sumlr(l, r)/2;
	unsigned long long cs = r;
	while (sumlr(cs, r) < midsum)
		cs--;
	xuat(choose(cs));
}

int main() {
	nhap();
	xuly();
	return 0;
}