#include<iostream>

using namespace std;

string n;
int main(){
	cin>>n;
	cout << (n[0]=='-'? n.size()-1:n.size());
	return 0;
}
//<=>if(n[0]=='-')
//	cout << n.size()-1;
//else
//	cout << n.size();