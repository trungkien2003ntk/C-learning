#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    double x,s1,s2; 
    int n;
    s1=s2=0;
    cout << "Nhap x: ";
    cin >> x;
    cout << "Nhap n: ";
    cin >> n;
    //Tong bai 68
    for (int i=1; i<=n; i++)
        if (i%2==0)
            s1 += pow(x,2*i);
        else
            s1 -= pow(x,2*i);
    
    cout << "Tong s1= " << s1 << endl;


    //Tong bai 69
    for (int i=0;i<=n; i++)
        if (i%2==0)
            s2 += pow(x,2*i+1);
        else
            s2 -= pow(x,2*i+1);
    cout << "Tong s2 = " << s2;
    return 0;
}