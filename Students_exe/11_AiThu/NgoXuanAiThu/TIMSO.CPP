#include<bits/stdc++.h>

using namespace std;

string str;
string cacso[]={"","ZERO","TWO","THREE","FOUR","FIVE"};

void nhap()
{
	getline(cin,str);
}

bool khongconkitu(string st)
{
	if (st.size()==0)
		return true;
	return false;
}

void tim_so(string str_sub,string st)
{
	string str_temp=str_sub;
	while (st.size()>0)
		if (str_temp[0]==st[0])
		{
			st.erase(0,1);
			str_temp.erase(0,1);
			if (khongconkitu(str_temp))
				break;
//			else if (!khongconkitu(st))
//				break;
		}
		else
			st.erase(0,1);
	if (khongconkitu(str_temp))
				cout <<str_sub;
}

void xuly()
{
	for (int i=1;i<=5;i++)
	{
		tim_so(cacso[i],str);
	}
}

int main()
{
	nhap();
	xuly();
	return 0;
}