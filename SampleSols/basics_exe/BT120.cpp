//Dinh nghia so chinh phuong: La so nguyen duong co tinh chat no la binh phuong cua mot so nguyen duong nao do. 
#include <iostream>
#include <cmath>
using namespace std;

bool chinhphuong(int x)
{
    if (x<1)
        return false;
    else
        {
            int i = sqrt(x);
            if (pow(i,2)==x)
                return true;
            else
                return false;
        }
}

int main()
{
    int n,cs;
    int storage[1000];
    cout << "Nhap n: ";
    cin >> n;
    cs = -1;
    for (int i=1;i<=n;i++)
        if (chinhphuong(i))
            {
                cs++;
                storage[cs] = i;
            }
    cout << "Cac so chinh phuong tu 1 den " << n << " la: " << endl;
    for (int i=0;i<=cs;i++)
        cout << storage[i] << "; ";
    return 0;
}