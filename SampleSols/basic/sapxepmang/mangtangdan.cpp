#include <iostream>

using namespace std;
int main()
{
    int n,csmax;
    float k;
    float arr[100];
    // Nhap du lieu
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cout << "Nhap phan tu thu " << i << ": ";
        cin >> arr[i];
    }
    
    // Tien trinh sap xep mang tang dan
    for (int i=1;i<=n-1;i++)
        for (int j=i+1;j<=n;j++)
            if (arr[i]>arr[j])
                {
                    k = arr[i];
                    arr[i] = arr[j];
                    arr[j] = k;
                }

    // Xuat mang da duoc sap xep
    cout << "Mang sau khi sap xep la: ";
    for (int i=1;i<=n;i++)
        cout << arr[i] << "; ";
    return 0;
}
