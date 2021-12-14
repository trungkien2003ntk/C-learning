#include <bits/stdc++.h>

using namespace std;
int L1,L2,R1,R2;
int tong1=0;
int tong2=0;
void nhap()
{
	ifstream f;
	f.open("DEMSO.INP");
	f>>L1>>R1;
	f>>L2>>R2;
	f.close();
}

bool kt_scp(int cp){
	int i=sqrt(cp);
	if(i*i==cp)
		return 1;
	return 0;
}
int scp(int a,int b){
	for(int i=a;i<=b;i++){
		if(kt_scp(i))
			tong1++;
	}
	return tong1;
}
bool kt_snt(int snt){
	if(snt==1)
		return 1;
	for(int i=2;i<snt;i++){
		if(snt%i==0)
			return 0;
	}
	return 1;
}
int snt(int a,int b){
	for(int i=a;i<=b;i++){
		if(kt_snt(i))
			tong2++;
	}
	return tong2;
}
void xuat(){
	ofstream f;
	f.open("DEMSO.OUT");
	f<< scp(L1,R1)<<" "<<snt(L2,R2);
	f.close();
}
int main(){
	nhap();
	xuat();
	return 0;
}