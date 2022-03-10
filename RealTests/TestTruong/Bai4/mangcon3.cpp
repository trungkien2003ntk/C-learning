#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int kq = 0;
vector<char> dat_in;
char tempt;

void xuly()
{
    while (cin.peek()!='\n'){
    	cin >> tempt;
    	while (find(dat_in.begin(),dat_in.end(),tempt) != dat_in.end())
    		dat_in.erase(dat_in.begin()); 
    	dat_in.push_back(tempt);
    	if (dat_in.size()>kq)
    		kq = dat_in.size();
	}
	cout << kq;
}

int main()
{
    xuly();
    return 0;
}