#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int tb[4][4];
int TOTAL,CENTER,AGG;

void nhap(){	
	ifstream f;
	f.open("hvdep.inp");
	for (int i=1;i<=3;i++)
		for (int j=1;j<=3;j++)
				f >> tb[i][j];
	f.close();
}

void builder(){
	if (tb[1][1]!=0 && tb[3][3]!=0)
		CENTER = (tb[1][1] + tb[3][3])/2;
	if (tb[1][2]!=0 && tb[3][2]!=0)
		CENTER = (tb[1][2] + tb[3][2])/2;
	if (tb[1][3]!=0 && tb[3][1]!=0)
		CENTER = (tb[1][3] + tb[3][1])/2;
	if (tb[2][1]!=0 && tb[2][3]!=0)
		CENTER = (tb[2][1] + tb[2][3])/2;
	TOTAL = CENTER * 3;
	if (tb[2][2]==0)
		tb[2][2] = CENTER;
}

void xuly(){
	AGG = TOTAL - CENTER;
	for (int i=1;i<=3;i++){
		if (tb[1][i]==0 && tb[3][4-i]!=0)
			tb[1][i] = AGG - tb[3][4-i];
		if (tb[1][i]!=0 && tb[3][4-i]==0)
			tb[3][4-i] = AGG - tb[1][i];
	}
	for (int i=1;i<=3;i+=2)
		if (tb[2][i]==0 && tb[2][4-i]!=0)
			tb[2][i] = AGG - tb[2][4-i];
	for (int i=1;i<=3;i+=2){
		for (int j=1;j<=3;j+=2){
			if (tb[i][j]==0 && tb[i][4-j]!=0)
				tb[i][j] = TOTAL - tb[i][2] - tb[i][4-j];
			if (tb[i][j]==0 && tb[4-i][j]!=0)
				tb[i][j] = TOTAL - tb[2][j] - tb[4-i][j];
		}
	}
}

void xuat(){
	ofstream f;
	f.open("hvdep.oup");
	for (int i = 1;i<=3;i++){
		for (int j=1;j<=3;j++)
			f << setw(6) << tb[i][j];
		f << endl;
	}
	f.close();
}

int main(){
	nhap();
	builder();
	xuly();
	xuat();
}