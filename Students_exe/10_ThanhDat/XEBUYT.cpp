#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int n,check[100000],cnt_check=0,a[100000],cnt=0,maina[100000],mainacnt=0;

bool duplicate(int temp)
{
	int cnt=0;
	for (int i=0;i<n;i++)
		if(temp==check[i])
			cnt++;
	if(cnt>=3)
		return 0;
	else
	{
		check[cnt_check++]=temp;
		return 1;
	}
}

void input()
{
	ifstream f;
	f.open("XB.INP");
	f>>n;
	int temp;
	for(int i=0;i<n;i++)
	{
		f>>temp;
		if(duplicate(temp))
			a[cnt++]=temp;
	}
	f.close();
}

void xuli()
{
	sort(a,a+cnt);
	for(int i=0;i<cnt;i++)
	{
		if(a[i]==a[i+1]&&a[i+1]==a[i+2])
		{
			maina[mainacnt++]=a[i];
			i=i+2;
		}
		else
			maina[mainacnt++]=a[i];
	}
	//	for(int i=0;i<mainacnt;i++)
	//	cout<<maina[i]<<" ";
	//cout<<maina[0]<<" ";
	for(int i=0;i<mainacnt;i++)
	{
		if(maina[i]==maina[i+1]-1)
		{
			int bienchay=i;
			while(maina[bienchay]==maina[bienchay-1]+1||maina[bienchay]==maina[bienchay-1])
			{
				bienchay++;
			}
			if(bienchay-i>=3)
			{
				i=i+bienchay-i-1;
				cout<<"-"<<" "<<maina[bienchay-1]<<" ";
			}
			else
				cout<<maina[i]<<" ";
			
		}
		else
			cout<<maina[i]<<" ";

	}
}


int main()
{
	input();
	xuli();
}
