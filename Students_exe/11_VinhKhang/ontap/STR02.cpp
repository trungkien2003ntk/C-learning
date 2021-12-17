#include <bits/stdc++.h>

using namespace std;
int T,cs=0;
string st,kq[100000];
string arr[10000];
void nhap(){
	cin>>T;
	cin.ignore();
}
bool lachuhoa(char kt){
	if('A'<=kt&&kt<='Z')
		return 1;
	return 0;
}
bool lachuthuong(char kt)
{
	if('a'<=kt&&kt<='z')
		return 1;
	return 0;
}
bool lachu(char kt)
{
	if(lachuthuong(kt)||lachuhoa(kt))
		return 1;
	return 0;
}
void xuli(){
	for(int i=1;i<=T;i++){
		getline(cin,arr[i]);
		st=arr[i];
		for(int j=0;j<st.size();j++){
			if(lachuhoa(st[j]))
				st[j]+='a'-'A';
		}
		for(int j=0;j<st.size();j++){
			if(lachu(st[j]))
				if(st[j-1]==' '||j==0)
				st[j]+='A'-'a';
		}
		cs++;
		kq[cs]=st;
	}
	for(int i=1;i<=T;i++)
		cout << kq[i] << endl;
}
int main(){
	nhap();
	xuli();
	return 0;
}