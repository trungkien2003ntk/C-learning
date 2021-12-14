#include<iostream>

using namespace std;

string n;

void nhap()
{
	cin >>n;
}

string reverse(string st)
{
	string sodadao="";
	bool checker=0;
	for (int i=st.size()-1;i>=0;i--)
	{
		if (!checker && st[i]=='0'){
			if (st[i-1]!='0')
				checker=1;
		}
		else 
			sodadao+=st[i];
	}
	return sodadao;
}

int main()
{
	nhap();
	cout <<reverse(n);	
	return 0;
}