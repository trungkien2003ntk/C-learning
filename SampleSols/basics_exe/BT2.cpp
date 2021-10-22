#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    long s=0;
    int n;
    cout << "Chuong trinh tinh S=1^2+2^2+3^2+...+n^2" << endl;
    cout << "Nhap n: " ;
    cin >> n; 
    for (int i=0; i<=n; i++)
        s += pow(i,2);
    cout << "Tong S =  " << s;
}