#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <stack>
#include <set>
using namespace std;

set<char> toantu = {'+', '-', 'x', ':', '^', '(', ')'};
string input_str;
vector<string> input_cooked;

void nhap()
{
	ifstream f("bai4.inp");
	f >> input_str;
	f.close();
}
// Kiem tra toan hang hay toan tu
int HoT(string x)
{
	if (x == "x" || x == ":" || x == "+" || x == "-" || x == "^")
		return 2;
	else
		return 1;
}
// Kiem tra thu tu uu tien toan tu
int UT(string x)
{
	if (x == "^")
		return 3;
	if (x == "x" || x == "/")
		return 2;
	else if (x == "+" || x == "-")
		return 1;
	else if (x == "(")
		return 0;

	return -1;
}
// Tinh moi phep toan
float cal_per_issue(string a, string relate, string b)
{
	int x, y;
	x = stoi(a);
	y = stoi(b);
	if (relate == "+")
		return (x + y);
	else if (relate == "-")
		return (x - y);
	else if (relate == "*")
		return (x * y);
	else if (relate == "/")
		return ((float)(x / y));
	return (pow(x, y));
}
// Cat mang nhap vao vao mot vector luu tru
void iter_s()
{
	int x = 0;
	int i = 1;
	string kq;
	while (x <= input_str.length())
	{
		if (toantu.find(input_str[x]) != toantu.end())
			kq = input_str.substr(x, 1);
		else
		{
			while (toantu.find(input_str[x + i]) == toantu.end())
				i++;
			kq = input_str.substr(x, i);
		}
		input_cooked.push_back(kq);
		x += i;
		i = 1;
	}
}

void xuly()
{
	stack<string> s_tu,s_hang ;
	vector<string>::iterator it;
	for (it=input_cooked.begin();it!=input_cooked.end();it++){
		
	}
}

int main()
{
	nhap();
	iter_s();
	xuly();
	return 0;
}