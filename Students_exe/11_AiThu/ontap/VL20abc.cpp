#include<bits/stdc++.h>

using namespace std;

unsigned long long n,arr[100000];
int T;

void nhap()
{
 	cin >>T;
	for (int i=1;i<=T;i++)
		cin >>arr[i];
}

unsigned long long tongchuso(unsigned long long so)
{
	int tong=0,du;
	while (so>0)
	{
		du=so%10;
		tong+=du;
		so=so/10;
	}
	return tong;
}

void xuly()
{
	unsigned long long sum,res[100000],cs=0;
	for (int i=1;i<=T;i++)
	{
		sum=tongchuso(arr[i]);
		cs++;
		res[cs]=sum;
	}
	for (int j=1;j<=T;j++)
		cout <<res[j] <<endl;
}

int main()
{
	nhap();
	xuly();
	return 0;
}