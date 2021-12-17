#include <bits/stdc++.h>

using namespace std;
string num;
string ans;
void nhap(){
	ifstream f;
	f.open("BAI2.INP");
	f>>num;
	f.close();
}

void Count(int CountNum[], string st){
	for (int i=0;i<st.size();i++){
		CountNum[st[i]-'0']++;
	}
//	for (int i=0;i<=9;i++){
//		cout<<CountNum[i]<<' ';
//	}
}

string Taora(string st, int CountNum[]){
	for (int i=0;i<10;i++){
		st.insert(0,CountNum[i],(char)(i+'0'));
	}
	return st;
}

long long TongChuSo(string num){
	long long Sum=0;
	for (long long i=0; i< num.size();i++)
		Sum+=num[i]-'0';
	return Sum;
}

void xuli(){
	int CountNum[10];
	fill_n(CountNum,10,0);
	bool TimThaySo0 = 0;
	
	long long Sum=TongChuSo(num);
	
	if (num.find('0')>0)
		TimThaySo0 =1;
//	Xet chia het cho 30
	if (TimThaySo0 && Sum%3==0){  
		Count(CountNum,num);   //Dem so luong tung so trong num va bo vao mang CountNum
		ans = Taora(ans,CountNum);   //Tao ra answer tu mang CountNum
	}
	else
		ans="-1";
}

void xuat(){
	ofstream f;
	f.open("BAI2.OUT");
	f<<ans;
	f.close();
}

int main(){
	nhap();
	xuli();
	xuat();
	return 0;
}