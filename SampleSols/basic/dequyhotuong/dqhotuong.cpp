// Chuong trinh tinh day so cho boi: 
//u1=1;
//v1=2;
//un+1=2un+3vn;
//vn+1=3un-4vn

#include <iostream>

using namespace std;
// Khai bao chuong trinh con ho tuong
int un(int x);
int vn(int x);

int un(int x)
{
    if (x==1)
        return 1;
    else
        return (2*un(x-1)+3*vn(x-1)); 
}

int vn(int x)
{
    if (x==1)
        return 2;
    else
        return (3*un(x-1)-4*vn(x-1));
}

int main() 
{
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << "Gia tri u(" << n << ")= " << un(n) << endl;
    cout << "Gia tri v(" << n << ")= " << vn(n) << endl;
    return 0;
}
