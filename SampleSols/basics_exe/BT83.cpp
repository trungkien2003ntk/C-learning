#include <iostream>

using namespace std;
int main()
{
    float a,b;
    cout << "Nhap so thuc a: ";
    cin >> a;
    cout << "Nhap so thuc b: ";
    cin >> b;
    if (a*b >=0)
        cout << a << " va " << b << " cung dau.";
    else
        cout << a << " va " << b << " khac dau.";
    return 0; 
}