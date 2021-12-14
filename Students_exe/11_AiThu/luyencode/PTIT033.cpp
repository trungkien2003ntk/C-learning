#include<iostream>

using namespace std;

int n,a,b;

void nhap()
{
    cin >>n >>a >>b;
}

void tinhchiahet()
{
    if (n%a==0 && n%b==0)
        cout << "Co, tat ca!";
    else
        if (n%a==0 && n%b!=0)
            cout << "Chi chia het cho a";
            else
                if (n%a!=0 && n%b==0)
                    cout << "Chi chia het cho b";
                    else
                        cout << "Khong chia het cho so nao ca";
}

int main()
{
    nhap();
    tinhchiahet();
    return 0;
}
