#include <iostream>

using namespace std;
int main()
{
    int n,k,maxcs,mincs;
    cout << "Nhap n: ";
    cin >> n;
    maxcs = mincs = n%10;
    while (n>0)
        {
            k = n%10;
            n /= 10;
            if (maxcs < k)
                maxcs = k;
            if (mincs > k)
                mincs = k;
        }
    cout << "Chu so lon nhat cua so " << n << " la: " << maxcs << endl;
    cout << "Chu so nho nhat cua so " << n << " la: " << mincs;
}