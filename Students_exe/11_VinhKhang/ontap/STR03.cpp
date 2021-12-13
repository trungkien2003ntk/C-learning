#include <bits/stdc++.h>

using namespace std;
string s,st;
int T,tong=0,cs=0;
int kq[101];
char arr[101];
void nhap()
{
	getline(cin,s);
	cin>>T;
	cin.ignore();
	for(int i=1;i<=T;i++)
		cin>>arr[i];
}
bool lachuhoa(char kt)
{
	if('A'<=kt&&kt<='Z')
		return 1;
	return 0;
}
char viet_thuong(char kt){
	if(lachuhoa(kt))
		return kt+'a'-'A';
	return kt;
}
void xuli(){
	for (int i=0;i<s.size();i++){
		s[i]=viet_thuong(s[i]);
	}
	for(int i=1;i<=T;i++){
		tong=0;
		for(int j=0;j<s.size();j++)
			if(s[j]==viet_thuong(arr[i]))
				tong++;
		cs++;
		kq[cs]=tong;
	}
	for(int i=1;i<=T;i++){
		cout << kq[i] << endl;
	}
}
int main(){
	nhap();
 	xuli();
	return 0;
}