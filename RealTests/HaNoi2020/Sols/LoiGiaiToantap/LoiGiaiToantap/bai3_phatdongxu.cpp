#include <bits/stdc++.h>
#include <string>

using namespace std;

// Bien toan cuc
long long n,m,players,no_turns;
string container="0";

// Tien khai bao
void nhap();
void xoay(long long x,long long y);
void khoitao();
long long find_out(long long x);
long long pos_length(long long x);
long long take(long long x,long long y);
long long max_item();
long long count_max();
void push_back(long long giatri,long long vitri);
void xuatkt();
void xuat();


void khoitao(){
	for (long long i=1;i<players;i++)
		container += " 0";
}

long long find_out(long long x){
	if (x==1)
		return 0;
	long long cs,counter;
	cs = 0;
	counter = 0;
	do{
		cs++;
		if (container[cs]==' ')
			counter++;
	}while (counter < x-1);
	cs++;
	return cs; 
}

long long pos_length(long long x){
	long long counter=0;
	while (container[x+counter] != ' ')
		counter++;
	return counter;
}

long long take(long long x,long long y){
	string st_output = container.substr(x,y);
	long long kq = stoll(st_output);
	return kq;
}

void push_back(long long giatri,long long vitri){
	string first_cont = "", last_cont = "", item;
	item = to_string(giatri);
	if (vitri <players){
		first_cont = container.substr(0,find_out(vitri));
		last_cont = container.substr(find_out(vitri)+pos_length(find_out(vitri)),container.length()-(first_cont.length()+pos_length(find_out(vitri))));
		container = first_cont + item + last_cont;
	}else{
		while (container[container.length()-1]!=' ')
			container.erase(container.length()-1,1);
		container += item;
	}
}

void xoay(long long x,long long y){
	long long cs = x;
	long long inc_num;
	while (cs != y){
		inc_num = take(find_out(cs),pos_length(find_out(cs)))+1;
		push_back(inc_num,cs);
		if (cs==y)
			break;
		if (cs==players)
			cs =1;
		else{
			cs++;
			if (cs==y){
				inc_num = take(find_out(cs),pos_length(find_out(cs)))+1;
				push_back(inc_num,cs);
				break;
			}
		}
	}
	
}


void xuatkt(long long x){
	cout << x << " -> " << container << endl;
}

void nhapxuly(){
	ifstream f;
	long long l,r;
	f.open("bai3.inp");
	f >> n >> m;
	players = n;
	no_turns = m;
	cout << players << " " << no_turns << endl;
	khoitao();
	for (long long i = 1;i<=no_turns;i++){
		f >> l >> r;
		xoay(l,r);
		xuatkt(i);
	}
	f.close();
}

long long max_item(){
	long long kq=0;
	for (int i=2;i<=players;i++)
		if (take(find_out(i),pos_length(find_out(i)))>kq)
			kq = take(find_out(i),pos_length(find_out(i)));
	return kq;
}

long long count_max(){
	long long kq = 0;
	long long item = max_item();
	for (int i=1;i<=players;i++)
		if ( item == take(find_out(i),pos_length(find_out(i))))
			kq++;
	return kq;
}

void xuat(){
	ofstream fo;
	fo.open("bai3.oup");
	fo << max_item() << ' ' << count_max();
	fo.close();
}


int main(){
	nhapxuly();
	xuat();
	
// Cac test de xu ly
//	container = "0 1234 2 353 4 5 6 7 8 9 10 11";
//	players = 12;
//	cout << "->"<< take(find_out(12),pos_length(find_out(12)))+11<< "<-";
//	push_back(take(find_out(12),pos_length(find_out(12)))+11,4);
//	xoay(5,2);
//	cout << container;
//	cout << max_item() << endl;
//	cout << count_max() << endl;
	
	return 0;
}