#include <bits/stdc++.h>

using namespace std;

string n;
int counter[10];

// Tien khai bao cac chuong trinh con

// Cac chuong trinh kiem tra tinh chia het
bool mod3(string x);
bool mod10(string x);

// Cac chuong trinh nhap xuat va xu ly
void nhap();
void xuat(string x);
void xuly();

//Cac chuong trinh xu ly so n de cho ra ket qua
unsigned long long tongcs(unsigned long long x);
void countnum(unsigned long long x);
string gtout();

//Chuong trinh nhap
void nhap(){
	ifstream f;
	f.open("bai2.inp");
	f >> n;
	f.close();
}

//Chuong trinh tinh tong chu so
unsigned long long tongcs(string x){
	unsigned long long kq = 0;
	while (x.length()>0){
		kq += x[0]-'0';
		x.erase(0,1);
	}
	return kq;
}

//Chuong trinh kiem tra chia het cho 3
bool mod3(string x){
	unsigned long long total = tongcs(x);
	if (total % 3 == 0)
		return true;
	return false;
}

//Chuong trinh kiem tra chia het cho 10
bool mod10(string x){
	int csf = x.find('0');
	if (csf==-1)
		return false;
	return true;
}

//Chuong trinh dem cac chu so trong n
void countnum(string x){
	while (x.length()>0){
		counter[x[0]-'0']++;
		x.erase(0,1);
	}
}

//Chuong trinh dua gia tri xuat ra
string gtout(){
	string result="";
	int i=9;
	while (i>=0){
		while (counter[i]>0){
			result = result+to_string(i);
			counter[i]--; 
		}
		i--;
	}
	return result;
}

//Chuong trinh xuat
void xuat(string x){
	ofstream f;
	f.open("bai2.oup");
	f << x;
	f.close();	
}

void xuly(){
	if (mod3(n) && mod10(n)){
		countnum(n);
		xuat(gtout());
	}else{
		xuat("-1");
	}
}

int main(){
	nhap();
	xuly();
	return 0;
}