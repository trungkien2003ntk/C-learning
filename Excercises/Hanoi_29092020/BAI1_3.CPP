#include <bits/stdc++.h>

using namespace std;
long long R,L,M;

void nhap(){
	ifstream f;
	f.open("BAI1.INP");
	f>>L>>R;
	f.close();
//	cout<<L<<" "<<R;
}

long long Sum(long long x,long long y){
	return (y-x+1)*(x+y)/2;
}

long long TimHangMinM2C(long long arr[1000][4], long long cs){
	long long HangMin = 0;
	for (long long hang = 0; hang < cs; hang ++){
		if (arr[hang][3]< arr[HangMin][3]){
			HangMin = hang;
		}
	}
	return HangMin;
}

void xuli_m2c(){
	long long SumTruoc,SumSau,ChenhLech,cs=-1,ans[10000][4];
	for (long long M = L; M <=R; M++){
		SumTruoc = Sum(L,M);
		SumSau  = Sum(M+1,R);
		ChenhLech = abs(SumTruoc - SumSau);
		cs++;
		ans[cs][0] = M;
		ans[cs][1] = SumTruoc;
		ans[cs][2] = SumSau;
		ans[cs][3] = ChenhLech;
	}
	long long HangItChenhNhat = TimHangMinM2C(ans,cs);
	M = ans[HangItChenhNhat][0];
}

long long TimVitriMinM1C(long long arr[10000], long long cs){
	long long VitriMin = 0;
	long Min = arr[0];
	for (long long Vitri = 0; Vitri <= cs; Vitri ++){
		if (arr[Vitri]< Min){
			Min = arr[Vitri];
			VitriMin = Vitri;
		}
	}
	return VitriMin;
}

void xuli_m1c(){
	long long SumTruoc,SumSau,ChenhLech,cs=-1,ChenhLechArr[10000], ChiSoChenhLech[10000];
	for (long long M = L; M <=R; M++){
		SumTruoc = Sum(L,M);
		SumSau  = Sum(M+1,R);
		ChenhLech = abs(SumTruoc - SumSau);
		cs++;
		ChiSoChenhLech[cs] = M;
		ChenhLechArr[cs] = ChenhLech;
	}
	long long VitriLechItNhat = TimVitriMinM1C(ChenhLechArr,cs);
	M = ChiSoChenhLech[VitriLechItNhat];	
}

void xuat(){
	ofstream f;
	f.open("BAI1_3.OUT");
	f<<M;
	f.close();
//	cout<<M;
}


int main(){
	nhap();
	//xuli_m1c();
	xuli_m2c();
	xuat();
	return 0;
}