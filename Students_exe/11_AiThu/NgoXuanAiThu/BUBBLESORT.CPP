#include<bits/stdc++.h>

using namespace std;

int arr[10000],n;

void nhap()
{
	cin>>n;
	for (int i=0;i<n;i++)
		cin >>arr[i];
}

void bubble_sort()
{
	for (int i=0;i<n;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			if (arr[i]>arr[j])
				swap(arr[i],arr[j]);
		}
	}
	for (int i=0;i<n;i++)
		cout <<arr[i] << " ";
}

int main()
{
	nhap();
	bubble_sort();
	return 0;
}