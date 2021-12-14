#include <bits/stdc++.h>
//xoa chuoi .erase
using namespace std;
string st1;string cacso;
string dayso[]={"", "ZERO","ONE","TWO","THREE","FOUR"};
void nhap(){
	getline(cin,st1);
}
bool hetchuoi(string s){
	if(s.size()==0)
		return 1;
	return 0;
}

void namtrong(string subst,string st){
	string sttemp=subst;
	while(0<st.size()){
		if(st[0]==sttemp[0]){
			st.erase(0,1);
			sttemp.erase(0,1);
			if(hetchuoi(sttemp))
				break;
		}
		else
			st.erase(0,1);
	}
	if(hetchuoi(sttemp))
		cout<< subst<<endl;
}
void xuli(){
	for(int i=1;i<=5;i++){
		namtrong(dayso[i],st1);
	}
}
int main(){
	nhap();
	xuli();
	return 0;
}