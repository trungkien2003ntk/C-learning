#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

void nhap();

int arr[1000],n;


void nhap(){
    ifstream f;
    f.open("LANLAP.INP");
    f>>n;
    for (int i=1;i<=n;i++){
        f>>arr[i];
    }
    f.close();
}

bool Check_Giong_Nhau(){
    for (int i=1;i<=n-1;i++)
        if (arr[i]!=arr[i+1])
            return false;
    return true;
}

void xuli(){
    int demlap=0;
    while (!Check_Giong_Nhau()){
        int temp=arr[1];
        for (int k=1;k<n;k++){
            arr[k]=abs(arr[k]-arr[k+1]);
        }
        arr[n]=abs(arr[n]-temp);
        demlap++;
        if (demlap>1000){
            demlap=-1;
            break;
        }
    }
    cout<<demlap;
}

int main(){
    nhap();
    xuli();

    return 0;
}









