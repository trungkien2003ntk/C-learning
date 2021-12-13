#include <bits/stdc++.h>

using namespace std;
string N;
void nhap(){
	getline(cin,N);
}
bool laso0(char kt){
	if(kt=='z'&&kt=='e'&&kt=='r'&&kt=='o')
		return 1;
	return 0;
}
bool laso1(char kt){
	if(kt=='o'&&kt=='n'&&kt=='e')
		return 1;
	return 0;
}
bool laso2(char kt	 ){
	if(kt=='t'&&kt=='w'&&kt=='o')
		return 1;
	return 0;
}
bool laso3(char kt){
	if(kt=='t'&&kt=='h'&&kt=='r'&&kt=='e')
		return 1;
	return 0;
}
bool laso4(char kt){
	if(kt=='f'&&kt=='o'&&kt=='u'&&kt=='r')
		return 1;
	return 0;
}
bool lachu(char kt){
	if('a'<=kt&&kt<='z'||'A'<=kt&&kt<='Z')
		return 1;
	return 0;
}
char viet_thuong(char kt){
	if('A'<=kt&&kt<='Z')
		return kt+'a'-'A';
	return kt;
}
void xuli()
{
	string st="";
	for(int i=0;i<N.size();i++){
		st=viet_thuong(N[i]);
	}
	for(int i=0;i<st.size();i++){
		if(lachu(N[i])){
			if(laso0(st[i]))
				cout << "ZERO";
			else
				if(laso1(st[i]))
					cout << "ONE";
				else
					if(laso2(st[i]))
						cout << "TWO";
					else
						if(laso3(st[i]))
							cout << "THREE";
						else if(laso4(st[i]))
								cout << "FOUR";
							else
								cout << "khong co trong chuoi";
		}
	}
}
int main(){
	nhap();
	xuli();
	return 0;
}