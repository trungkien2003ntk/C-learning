#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iostream>
using namespace std;

int random(int minN, int maxN){
    return minN + rand() % (maxN + 1 - minN);
}
 
int main(){
    srand((int)time(0));
    int n,r;
    cout << "Nhap so phan tu mang tao thanh: ";
    cin >> n;
	ofstream f("bai3.inp");
	f << n << endl;    
    for(int i = 0; i < n; ++i){
        r = random(-1000,1000);
        f << r << " ";
    }
    f.close();
}