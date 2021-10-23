#include <iostream>

using namespace std;

// Khai bao chuong trinh con
int fibo(int x)
{
    if ((x==1) || (x==2))
        return 1;
    else
        return (fibo(x-1)+fibo(x-2));
}

// Chuong trinh chinh
// Van de cua de quy la cham va khi de quy so luong lon se mat tg thuc thi va co the dan den tran bo nho
int main()
{
    int n;
    char option;
    cout << "Ban muon xuat so fibonaci thu may?? ";
    cin >> n;
    cout << "So fibonacci thu " << n << " la: " << fibo(n) << endl;
    cout << "Ban co muon xuat day fibonacci den so hang thu n khong? (y/n): ";
    cin >> option;
    if (option == 'y')
        {
            
            for (int i=1;i<=n;i++)
                cout << fibo(i) << "; ";
        }
    return 0;
}