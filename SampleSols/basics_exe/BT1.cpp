#include <iostream>

using namespace std;

int main()
{
    int n;
    long s=0;
    cout << "Chuong trinh tinh tong S=1+2+3+...+n" << endl;
    cout << "Nhap n: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
        s+=i;
    cout << "Tong S= " << s;
}
