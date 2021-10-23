#include <iostream>

using namespace std;

int main()
{
    int i,n;
    long s=0;
    cout << "Chuong trinh tinh tong S=1+2+3+...+n" << endl;
    cout << "Nhap n: ";
    cin >> n;
    i=0;
    while (i<n)
        {
            i++;
            s+=i;
        };
    cout <<"Tong S= " << s;
    return 0;
}
