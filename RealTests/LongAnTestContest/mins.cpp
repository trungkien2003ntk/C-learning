#include <iostream>
#include <set>
#include <string>

using namespace std;

void nhapxuly(){
	int n;
	set<int> datIn;
	string s;
	cin >> s;
	while (s.size()>0){
		if (s[0]>='0' && s[0]<='9'){
			int j = 0;
			while (s[j]>='0' && s[j] <='9')
				j++;
			string tempt = s.substr(0,j);
			n = stoi(tempt);
			datIn.insert(n);
			s.erase(0,j);
		}
		else s.erase(0,1);
	}
	auto it = datIn.begin();
	cout << *it;
}

int main(){
	nhapxuly();
	return 0;
}