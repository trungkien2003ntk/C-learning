#include <bits/stdc++.h>
#include <vector>
using namespace std;

int kq = 0;
vector<char> dat_in;
string tempt;

void xuly()
{
    cin >> tempt;
    int i=0;
    while (i<tempt.size()){
    	while (find(dat_in.begin(),dat_in.end(),tempt[i]) != dat_in.end())
    		dat_in.erase(dat_in.begin()); 
    	dat_in.push_back(tempt[i]);
    	if (dat_in.size()>kq)
    		kq = dat_in.size();
    	i++;
	}
	cout << kq;
}

int main()
{
    xuly();
    return 0;
}