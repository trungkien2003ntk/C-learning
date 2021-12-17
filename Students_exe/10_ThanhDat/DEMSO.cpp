//Sai kiem tra nguyen to
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int L1,R1;
int L2,R2;
int countTu=0;
int countHai=0;

void nhap()
{   
    ifstream f;
    f.open("DEMSO.INP");
    f>>L1>>R1>>L2>>R2;
    f.close();
}

bool perfectsquare(int x)
{
    if(sqrt(x)==round(sqrt(x)))
        return 1;
    else
        return 0;
}
bool prime(int x)
{
    for(int i=2;i<x;i++){
        if(x%i==0) 
        {
            
        return 0;
        break;
        }
    }
    return 1;
}

void xuli()
{   
    for(int x=L1;x<=R1;x++) {
        if(perfectsquare(x))
            countHai++;
    }
    
    for(int x=L2;x<=R2;x++) {
        if(prime(x))
            countTu++;
    }
}
void xuat()
{   
    ofstream f;
    f.open("DEMSO.OUT");
    f<<countHai<<" "<<countTu;
    f.close();
}

int main()
{
    nhap();
    xuli();
    xuat();
    return 0;
}
