#include <iostream>
#include <string>

using namespace std;

int n,maxOutput=0;
int sn[10000],L[10000][10000],M[10000][10000];

void nhap(){
	cin >> n;
	for (int i=1;i<=n;i++)
		cin >> sn[i];
}

void khoiTao(){
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++)
			M[i][j]=L[i][j]=0;
}

void xuly(){
	int k;
	for (int i=1;i<n;i++)
		for (int j=1;j<=i;j++){
			if (i==j){
				M[i][i]=sn[i];
				L[i][i]=1;
			} else {
				k=1;
				for (int p=2;p<j;p++)
					if ((L[i][p]>L[i][k]) || (L[i][p]==L[i][k] && sn[p]<sn[k]))
						k=p;
				if (M[i][j]<sn[j]){
					L[i][j] = L[i][k] +1;
					M[i][j] = sn[j];
				} else {
					L[i][j] = L[i][k];
					M[i][j] = M[i][k];
				}
			}
			if (maxOutput<L[i][j])
				maxOutput = L[i][j];
		}
}

void xuat(){
	cout << maxOutput;
}

int main(){
	nhap();
	khoiTao();
	xuly();
	xuat();
	return 0;
}