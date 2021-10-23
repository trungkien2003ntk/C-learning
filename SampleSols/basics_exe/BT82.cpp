// Chuong trinh tim so lon nhat trong 3 so a,b,c
#include <iostream>

using namespace std;

int main()
{
    int a,b,c,max;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;
    cout << "Nhap c: ";
    cin >> c;
    max = a;
    if (max<b)
        max = b;
    if (max<c)
        max = c;
    cout << "So lon nhat trong 3 chu so a,b,c la: " << max;
    return 0;
}