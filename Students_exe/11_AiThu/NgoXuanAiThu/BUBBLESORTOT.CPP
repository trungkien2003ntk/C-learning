#include<bits/stdc++.h>

using namespace std;

int arr[10000],n;
char luachon;

void nhap()
{
	cout << "Ban muon sap xep nhu the nao?" <<endl;
	cout << "1-Sap xep tu be den lon" <<endl;
	cout << "2-Sap xep tu lon den be" <<endl;
	cout << "3-Ca hai lua chon tren" <<endl;
	cout << "Vui long chon 1 trong 3: ";
	cin >>luachon;
	cout << "So chu so can nhap: ";
	cin>>n;
	for (int i=0;i<n;i++)
		cin >>arr[i];
}

void bubble_sort_tang(int x)
{
	for (int i=0;i<x;i++)
	{
		for (int j=i+1;j<x;j++)
		{
			if (arr[i]>arr[j])
				swap(arr[i],arr[j]);
		}
	}
	for (int i=0;i<x;i++)
	{
		cout <<arr[i] << " ";
	}
	cout <<endl;
}

void bubble_sort_giam(int x)
{
	for (int i=0;i<x;i++)
	{
		for (int j=i+1;j<x;j++)
		{
			if (arr[i]<arr[j])
				swap(arr[i],arr[j]);
		}
	}
	for (int i=0;i<x;i++)
		cout <<arr[i] << " ";
}

void xuly()
{
	if (luachon=='1')
		bubble_sort_tang(n);
	else if (luachon=='2')
		bubble_sort_giam(n);
	else
	{
		bubble_sort_tang(n);
		bubble_sort_giam(n);
	}
}

int main()
{
	nhap();
	xuly();
	return 0;
}