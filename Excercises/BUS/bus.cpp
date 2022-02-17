#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int N,maxN,minN,arr_inp[10000];

void nhap(){
    ifstream f;
    f.open("XB.INP");
    f >> N;
    int tempt;
    maxN = minN = 0;
    for (int i=1;i<=N;i++){
        f >> tempt;
        if (maxN == 0 || maxN < tempt) 
            maxN = tempt;
        if (minN == 0 || minN > tempt)
            minN = tempt;
        arr_inp[tempt]++;
    } 
    f.close();
}

void xuly(){
    int i = minN;
    string oup = "";
    while (i<=maxN){
        if (arr_inp[i]>0)
            if (arr_inp[i]==2 && (arr_inp[i+1]==0 || (arr_inp[i+1]>0 && arr_inp[i+2]==0))){
                oup += " " + to_string(i) + " " + to_string(i); 
                i++;
            } else {
                int j = 0;
                while (arr_inp[i+j]>0)
                    j++;
                j--;
                if (j>=2){
                    oup += " " + to_string(i) + " - " + to_string(i+j);
                    i += j+1;
                };
                if (j==0 || j==1){
                    oup += " " + to_string(i);
                    i++; 
                };
            } 
        else i++; 
    }
    cout << oup;
}

int main(){
    nhap();
    xuly();
    return 0;
}