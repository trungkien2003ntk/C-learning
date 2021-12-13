#include <bits/stdc++.h>

using namespace std;
string st;
int i;
void nhap()
{
	getline(cin,st);
}
bool lachuhoa(char kt)
{
	if('A'<=kt&&kt<='Z')
		return true;
	return false;
}
void xuli(){
	for(int i=0;i<st.size();i++){
		if(lachuhoa(st[i]))
			st[i]+='a'-'A';
	}
	for(int i=0;i<st.size();i++)
	{
		cout << st[i];
	}
}
int main(){
	nhap();
	xuli();
	return 0;
}