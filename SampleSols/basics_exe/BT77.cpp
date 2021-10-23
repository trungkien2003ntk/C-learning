#include <iostream>

using namespace std;

int main()
{
    int n;
    long s=0;
    cout << "Nhap n: ";
    cin >> n;
    for (int i=0;i<=n; i++)
        s += i;
    cout << "Tong S= " << s;
    return 0;
}