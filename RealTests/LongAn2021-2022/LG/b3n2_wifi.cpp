#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

long long M,N,K,maxB,countMaxB,coor_x[1000],coor_y[1000],range_R[1000],bandwidth_B[1000],MAX_X,MAX_Y,MAX_R;
void Nhap(){
	ifstream f;
	f.open("wifi.inp");
	f >> M >> N >> K;
	for (int i=1;i<=K;i++)
		f >> coor_x[i] >> coor_y[i] >> range_R[i] >> bandwidth_B[i];
	f.close();
}

void NhapInline(){
	cin >> M >> N >> K;
	for (int i=1;i<=K;i++)
		cin >> coor_x[i] >> coor_y[i] >> range_R[i] >> bandwidth_B[i];
}
void KhoiTao(){
	MAX_X = coor_x[1];
	MAX_Y = coor_y[1];
	MAX_R = range_R[1];
	for (int i=2;i<=M;i++){
		if (MAX_X < coor_x[i])
			MAX_X = coor_x[i];
		if (MAX_Y < coor_y[i])
			MAX_Y = coor_y[i];
		if (MAX_R < range_R[i])
			MAX_R = range_R[i];
	}	
	MAX_X += MAX_R;
	MAX_Y += MAX_R;
}

float Distance(long long x1,long long y1,long long x2, long long y2){
	return (sqrt(pow((x1-x2),2)+pow((y1-y2),2)));
}

long long Speed(long long x,long long y){
	long long kq=0;
	for (int i=1;i<=K;i++)
		if (Distance(x,y,coor_x[i],coor_y[i])<=range_R[i])
			kq += bandwidth_B[i];
	return kq;
}

void XuLy(){
	maxB = countMaxB=0;
	for (int i=1;i<=MAX_X;i++)
		for (int j=1;j<=MAX_Y;j++){
			if ((maxB == 0)||(maxB<Speed(i,j))){
				maxB = Speed(i,j);	
				countMaxB = 1;
			}
			else if (maxB == Speed(i,j)){
				countMaxB++;
//				cout << "(i,j)=(" << i << "," << j << ")" << endl; 
			}
		}
//	cout << maxB << " " << countMaxB;
}

void Xuat(){
	ofstream f;
	f.open("wifi.out");
	f << maxB << endl;
	f << countMaxB;
	f.close();	
}

void XuatInline(){
	cout << maxB << endl;
	cout << countMaxB;
}

int main(){
	NhapInline();
	KhoiTao();
	XuLy();
	XuatInline();
	return 0;
}