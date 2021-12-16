#include <bits/stdc++.h>
#include <string>

using namespace std;

// Bien toan cuc
unsigned long long n,m,players,no_turns;
string container="0";

// Tien khai bao
//void nhap();
//void xoay(int x,int y);
//void khoitao();
unsigned long long find_out(unsigned long long x);
//unsigned long long pos_length(unsigned long long x);
//unsigned long long take(unsigned long long x,unsigned long long y);
//void push_back(unsigned long long giatri,unsigned long long vitri);
//void xuatkt();
//
//void khoitao(){
//	for (unsigned long long i=1;i<players;i++){
//		container += " 0";
//	}
//}

unsigned long long find_out(unsigned long long x){
	unsigned long long cs,counter;
	cs = 0;
	counter = 0;
	while (counter<x-1){
		cs++;
		if (container[cs]==' ')
			counter++;
	}
	cs++;
	return cs; 
}
//
//unsigned long long pos_length(unsigned long long x){
//	unsigned long long counter=0;
//	while (container[x+counter] != ' ')
//		counter++;
//	return counter;
//}
//
//unsigned long long take(unsigned long long x,unsigned long long y){
//	string st_output = container.substr(x,y);
//	unsigned long long kq = strtoull(st_output);
//	return kq;
//}
//
//void push_back(unsigned long long giatri,unsigned long long vitri){
//	string first_cont = "", last_cont = "", item;
//	item = to_string(giatri);
//	first_cont = container.substr(0,find_out(vitri));
//	last_cont = container.substr(find_out(vitri)+pos_length(find_out(vitri)),container.length()-(first_cont.length()+pos_length(find_out(vitri))));
//	container = first_cont + item + last_cont;
//}
//
//void xoay(unsigned long long x,unsigned long long y){
//	unsigned long long cs = x;
//	unsigned long long inc_num;
//	while (cs != y){
//		inc_num = take(find_out(cs),pos_length(find_out(cs)))+1;
//		push_back(inc_num,cs);
//		if (cs==y)
//			break;
//		if (cs==players)
//			cs =1;
//		else 
//			cs++;
//	}
//	
//}
//
//void xuatkt(){
//	cout << container << endl;
//}
//
//void nhap(){
//	ifstream f;
//	unsigned long long l,r;
//	f.open("bai3.inp");
//	f >> n >> m;
//	players = n;
//	no_turns = m;
//	for (int i = 1;i<=no_turns;i++){
//		f >> l >> r;
//		xoay(l,r);
//		xuatkt();
//	}
//	f.close();
//}



int main(){
//	khoitao();
//	nhap();
	container = "0 1 2 3 4 5 6 7 8 9 10 11";
	cout << "->"<< find_out(6) << "<-";
	return 0;
}