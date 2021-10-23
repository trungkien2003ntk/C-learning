#include <iostream>

using namespace std;

bool snt(int x)
{   
    bool kq = true;
    for (int k=2;k<=x/2;k++)
        if (x%k==0)
            kq = false;
    return kq;
}


int main()
{
    int n,cs;
    int storage[1000];
    cout << "Nhap n: ";
    cin >> n;
    cs = -1;
    for (int i=2;i<=n;i++)
        if (snt(i))
            {
                cs++;
                storage[cs] = i;
            }
    cout << "Tap hop tat ca cac so nguyen to nho hon n la: " << endl;
    for (int i=0;i<=cs;i++)
        cout << storage[i] << "; ";
    return 0;
}