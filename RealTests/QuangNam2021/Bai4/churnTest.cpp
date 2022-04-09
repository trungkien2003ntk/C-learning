#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;

int random(int a, int b)
{
      srand(time(NULL));
   
      int r = rand()%2;

      if(r==0)
            return a;
      else
            return b;
}

int main(){
	int k,t;
	cout << "Nhap K: ";
	cin >> k;
	cout << "Length string: ";
	cin >> t;
	string s="";
	for (int i=1;i<=t;i++){
		int it = random(0,1);
		s += to_string(it);
	}
		
	ofstream f("xaucon.inp");
	f << k << endl;
	f << s;
	f.close();
}