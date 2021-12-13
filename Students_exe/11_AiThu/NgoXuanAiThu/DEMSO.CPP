#include<bits/stdc++.h>

using namespace std;

int L1,R1,L2,R2;

void nhapfile()
{
	ifstream f;
	f.open("DEMSO.INP");
	f >>L1 >>R1;
	f >>L2 >>R2;
	f.close();
}

bool kt_scp(int k)
{
	int i=sqrt(k);
	if (i*i==k)
		return true;
	return false;
}

int chinh_phuong(int x,int y)
{
	int tong=0;
	for (int i=x;i<=y;i++)
	{
		if (kt_scp(i))
			tong++;
	}
	return tong;
}

bool kt_snt(int k)
{
	if (k<=1)
		return false;
	for (int i=2;i<=round(sqrt(k));i++)
	{
		if (k%i==0)
			return false;
	}
	return true;
}

int nguyen_to(int x,int y)
{
	int tong=0;
	for (int i=x;i<=y;i++)
	{
		if (kt_snt(i))
			tong++;
	}
	return tong;
}

void xuatfile()
{
	ofstream f;
	f.open("DEMSO.OUT");
	f <<chinh_phuong(L1,R1) << " " <<nguyen_to(L2,R2);
	f.close();
}

int main()
{
	nhapfile();
	xuatfile();
	return 0;
}