#include <iostream>

using namespace std;

int main()
{
    //Chuong trinh tim so nguyen duong n nho nhat sao cho 1+2+3+...+n >10000
    long s,n;
    s=n=0;
    do
    {
        n++;
        s+=n;
    }
    while (s<=10000);
    s -=n;
    n--;
    cout << "s = " << s << "; n = " << n;
}