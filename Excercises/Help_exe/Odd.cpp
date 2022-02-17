#include <iostream>
#include <fstream>

using namespace std;

long long x[50],t[50],q,money[16]={1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000,0};
static long long bangPA[16][200000];
long long tempt,returnKq[50],cs=0;
void xuly();
void xuat();
void khoiTao();

void nhap(){
	cin >> q;
	for (long long i=1;i<=q;i++)
		cin >> x[i] >> t[i];	
	fill_n(returnKq,50,0);
	cout << x[1] << " " << t[1];
}

void khoiTao(long long chiSoQues){
	money[15]=x[chiSoQues];
	for (int j=0;j<16;j++){
		bangPA[0][j]=0;
		bangPA[1][j]=1;
		bangPA[2][j]=2;
	}
	for (int i=0;i<=t[chiSoQues];i++){
		bangPA[i][0]=0;
		bangPA[i][1]=i;
	}
}

long long min_before(long long dong, long long cot){
	long long kq = bangPA[dong][1];
	for (int j=2;j<=cot;j++)
		if (kq<bangPA[dong][j])
			kq = bangPA[dong][j];
	return kq;
}

void xuly(){
	for (int i=1;i<=q;i++){
		khoiTao(i);
		for (int j=3;j<16;j++)
			for (int k=2;k<=t[i];k++){
				tempt = min_before(j,k-1);
				if (j-money[k-1]>=0)
					bangPA[j][k]=min(bangPA[j-money[k-1]][k]+1,tempt);
				else
					bangPA[j][k]=tempt;
			}
		ofstream f;
		f.open("odd.oup");
		f << x[1] << " " << t[1] << endl;
		for (int j=0;j<t[i];j++){
			for (int k=0;k<=16;k++)
				f << bangPA[j][k] << ' ';
			f << endl;
		}
		f.close();
		}
}

int main(){
	nhap();
	xuly();
	return 0;
}