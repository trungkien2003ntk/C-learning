#include <iostream>
#include <string>

using namespace std;

int k;
string s;

void nhapxuly(){
	cin >> k >> s;
	int track[s.size()+1];
	track[0]=0;
	
	for (int i=0;i<s.size();i++)
		if (s[i]=='1')
			track[i+1] = track[i]+1;
		else 
			track[i+1] = track[i];

	int counter = 0;
	for (int i=0;i<s.size();i++)
		for (int j=i+1;j<s.size()+1;j++)
			if (track[j]-track[i]==k)
				counter++;
	cout << counter;
}

int main(){
	nhapxuly();	
	return 0;
}