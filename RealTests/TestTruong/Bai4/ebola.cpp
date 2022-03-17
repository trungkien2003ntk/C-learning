#include <iostream>
#include <set>
#include <string>
using namespace std;

int n,k,counter;
set<string> dat;

void xuly(){
	string tempt;
	cin >> n >> k;
	counter = k+1;
	while (counter>0){
		getline(cin,tempt); 
		counter--;
	}
	
	while (tempt[0]!=' ')
		tempt.erase(0,1);
	tempt.erase(0,1);
	string ip="";
	
	while (tempt.size()>0){
		while (tempt[0]!=' ' && tempt.size()>0){
			ip += tempt[0];
			tempt.erase(0,1);
		}
		dat.insert(ip);
		tempt.erase(0,1);
		ip="";
	}
	dat.insert(to_string(k));
	cout << dat.size() << endl;
	for (set<string>::iterator it=dat.begin();it!=dat.end();it++)
		cout << *it << ' ';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    xuly();
    return 0;
}