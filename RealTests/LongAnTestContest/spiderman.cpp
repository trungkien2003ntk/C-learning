#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n,resHeight=0;
string result="",tracker="";
vector<int> datIn,datProcess;
void nhap(){
	int tempt;
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> tempt;
		datIn.push_back(tempt);
	}
	for (int i=1;i<=n;i++)
		datProcess.push_back(0);
}

void xuly(int x,int currentRes,string trace){
	if (x == n && currentRes == 0){
		long long temptSum=datProcess[0];
		for (long long i=1;i<datProcess.size();i++)
			if (temptSum < datProcess[i])
				temptSum = datProcess[i];
		if (temptSum > resHeight){
			result = trace;
			resHeight = temptSum;
		}
	}
	else{
		if (x+1<=n && currentRes + datIn[x]>=0)
			{
				datProcess[x]=currentRes+datIn[x];
				xuly(x+1,currentRes+datIn[x],trace+"U");
				datProcess[x]=0;
			}
		if (x+1<=n && currentRes - datIn[x]>=0){
			datProcess[x]=currentRes-datIn[x];
			xuly(x+1,currentRes-datIn[x],trace+"D");
			datProcess[x]=0;
		}
	}
}

void xuat(){
	if (result =="")
		cout << "IMPOSSIBLE";
	else
		cout << result;
}

int main(){
	nhap();
	xuly(0,0,tracker);
	xuat();
	return 0;
}