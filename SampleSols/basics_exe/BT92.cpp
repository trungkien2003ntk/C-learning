#include <iostream>

using namespace std;
int main()
{
    int ucln,a,b;
    cout << "Nhap so tu nhien a>0: ";
    cin >> a;
    cout << "Nhap so tu nhien b>0: ";
    cin >> b;
    if (a>=b)
        ucln = b;
    else 
        ucln = a;
    while ((a%ucln!=0) || (b%ucln!=0))
        ucln--;
    cout << "uoc chung lon nhat la: " << ucln;
}