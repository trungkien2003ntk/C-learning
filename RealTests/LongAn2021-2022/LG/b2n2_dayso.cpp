#include <iostream>
#include <fstream>
using namespace std;

long long N,M,S,MAX,MIN,START_DES,END_DES,TRACKTOR_LENGTH;
long long A[100000],TRACKTOR[100000];
bool INSIDER[100000];

void Nhap(){
	ifstream f;
	f.open("dayso.inp");
	f >> N >> M >> S;
	for (int i=1;i<=M;i++)
		f >> A[i];	
	f.close();
}

void KhoiTao(){
	// Khoi tao vi tri bat dau xu ly
	MAX = MIN = A[1];
	int i = 1;
	while (i<M){
		i++;
		if (MAX < A[i])
			MAX = A[i];
		if (MIN > A[i])
			MIN = A[i];
	}
	START_DES = MIN-2;
	END_DES = MAX+2;
	TRACKTOR_LENGTH = MAX-MIN+4;
	for (int i=0;i<=TRACKTOR_LENGTH;i++)
		TRACKTOR[i] = START_DES + i;
	// Khoi tao danh dau insiders
	fill_n(INSIDER,TRACKTOR_LENGTH,0);
	for (int i=1;i<=M;i++)
		INSIDER[A[i]-START_DES]=1;
}

bool BorrowCounter(long long x){
	long long counter=0;
	for (int i=x;i<x+M;i++){
		if (INSIDER[i]==0)
			counter++;
		if (counter>2)
			break;	
	}
	if (counter>2)
		return false;
	return true;
}

void xuat(long long x){
	cout << x;
}

void xuly(){
	long long dem=0;
	for (int i=0;i<=TRACKTOR_LENGTH-M+1;i++)
		if (BorrowCounter(i))
			dem++;
	xuat(dem);
}


int main(){
	Nhap();
	KhoiTao();
	xuly();
}