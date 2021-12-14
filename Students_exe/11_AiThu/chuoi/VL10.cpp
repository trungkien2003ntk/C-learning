#include<iostream>

using namespace std;

string n;

void nhap()
{
	cin >>n;
}

void xuly()
{
	cout <<(n[0]=='-' ? n.size()-1:n.size());
	// if (n[0]=='-')
		// cout <<n.size()-1;
//	else 
//		cout <<n.size();	
}

int main()
{
	nhap();
	xuly();
	return 0;
}