#include <iostream>
#include <string>
using namespace std;

int M,S,MAX_TOTAL,MIN_TOTAL;
string min_result,max_result;

void nhap(){
	cin >> M >> S;
	MAX_TOTAL = MIN_TOTAL = S;
}

bool check(){
	if (S!=0 && S/9<=M)
		return true;
	return false;
}

void xuly(){
	// Khoi tao xu ly khi S>0
	min_result = "";
	for (int i=1;i<=M;i++)
		min_result += '0';
	max_result = min_result;
	// Xu ly max
	int cs = 0;
	while (MAX_TOTAL>9)
		{
			max_result[cs]= '9';
			cs++;
			MAX_TOTAL -= 9;
		}
	string last_digit = to_string(MAX_TOTAL); 
	max_result[cs] = last_digit[0];
	// Xu ly min
	MIN_TOTAL -=1;
	min_result[0] = '1';
	cs = min_result.length()-1;
	while (MIN_TOTAL>9){
		min_result[cs] = '9';
		cs--;
		MIN_TOTAL -= 9;
	}
	if (cs==0)
		MIN_TOTAL++;
	last_digit = to_string(MIN_TOTAL);
	min_result[cs] = last_digit[0];
}	

void xuat(){
	if (S==0 && M==1)
		cout << "0 0";
	else if (!(check()))
		cout << "-1 -1";
	else{
		xuly();
		cout << min_result << " " << max_result;
	}
	
}

int main(){
	nhap();
	xuat();
}