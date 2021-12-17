#include <bits/stdc++.h>

using namespace std;

int main(){
	long long num,turns;
	srand(time(0));
	num = rand()%50+40;
	turns = rand()%30+20;
	
	ofstream f;
	f.open("bai3_auto.inp");
	f << num << " " << turns << endl;
	for (int i=1;i<=turns;i++)
		f << rand()%num << " " << rand()%num << endl;
	f.close();
}