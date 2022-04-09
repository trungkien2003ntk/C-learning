#include <bits/stdc++.h>
using namespace std;

int eratos[1000001]={0};
int n;

void nhapTho(){
	n = 1000000;
}

void dperatos(){
	eratos[0]=eratos[1]=1;
	for (int x=2;x*x<=1000001;x++){
		if (eratos[x]==0){
			for (int i=x*x;i<=1000001;i=i+x)
				if (eratos[i]==0)
					eratos[i]=1;
		}
	}
}
int main(){
	nhapTho();
	dperatos();
	int res=0;
	for (int x=n/2;x>=1;x++){
		if (eratos[x]==0 && eratos[n-x]==0)
			res++;
	}
	cout << res;
	return 0;
}