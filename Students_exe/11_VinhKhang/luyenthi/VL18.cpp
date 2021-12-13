#include <iostream>
#include <string>
using namespace std;

string st;
void nhap()
{
	cin>>st;
}

string chuoidao(string st1){
	string daochuoi="";
	bool check=0;
	for(int i=st1.size()-1;i>=0;i--)
	{
		if(!check&&st1[i]=='0')
			check=1;
			daochuoi+=st1[i];
	}
	return daochuoi;
}

int main()
{
	nhap();
	return 0;
}