#include <iostream>

using namespace std;

int n;
float arr[100];

void nhap()
{
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
}

void nhapmang()
{
    for (int i=1;i<=n;i++)
    {
        cout << "Phan tu thu " << i << " cua mang la: ";
        cin >> arr[i];
    }
}

void xuat()
{
    for (int i=1;i<=n;i++)
        cout << "a[" << i << "]= " << arr[i] << endl;
}

int main()
{
    nhap();
    nhapmang();
    xuat();
}
