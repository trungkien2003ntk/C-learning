#include <iostream>

using namespace std;

int main()
{
    int n;
    long s=0;
    cout << "Nhap n: ";
    cin >> n;
    for (int i=0; i<=n; i++)
        if (i%2==1)
            s+=i;
    cout << "S= " << s;
}