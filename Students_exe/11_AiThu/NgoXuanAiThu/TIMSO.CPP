#include<bits/stdc++.h>

using namespace std;

string str;

void nhap()
{
	getline(cin,str);
}

string tim_so(string st)
{
	string sotimduoc="";
	bool check=0;
	for (int i=0;i<st.size();i++){
		if (st[i]=='Z'){
			sotimduoc+=st[i];
			if (st[i]=='E'){
				sotimduoc+=st[i];
				if (st[i]=='R'){
					sotimduoc+=st[i];
					if (st[i]=='O')
						sotimduoc+=st[i];
				}
			}
		}
		if (st[i]=='O'){
			sotimduoc+=st[i];
			if (st[i]=='N'){
				sotimduoc+=st[i];
				if (st[i]=='E'){
					sotimduoc+=st[i];
			}
		}
	}
		if (st[i]=='T'){
			sotimduoc+=st[i];
			if (st[i]=='W'){
				sotimduoc+=st[i];
				if (st[i]=='O')
					sotimduoc+=st[i];
			}
			else if (st[i]=='H'){
				sotimduoc+=st[i];
				if (st[i]=='R'){
					sotimduoc+=st[i];
					if (st[i]=='E'){
						sotimduoc+=st[i];
						if (st[i]=='E'){
							sotimduoc+=st[i];
						}
					}
				}
			}
		}
		if (st[i]=='F'){
			sotimduoc+=st[i];
			if (st[i]=='O'){
				sotimduoc+=st[i];
				if (st[i]=='U'){
					sotimduoc+=st[i];
					if (st[i]=='R'){
						sotimduoc+=st[i];
					}
				}
			}
			else if (st[i]=='I'){
				sotimduoc+=st[i];
				if (st[i]=='V'){
					sotimduoc+=st[i];
					if (st[i]=='E'){
						sotimduoc+=st[i];
					}
				}
			}
		}
	}
	return sotimduoc;
}

void xuly()
{
	string so=tim_so(str);
	cout <<so;
}

int main()
{
	nhap();
	xuly();
	return 0;
}