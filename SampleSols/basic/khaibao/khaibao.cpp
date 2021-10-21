//Khai bao bien co ban
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int a,b;
    a=b=2;
    a+=1;
    a++;
    cout<<setprecision(17);
    cout<<"a= "<<a<<"; b= "<<b<<endl;
    float c;
    //Static_cast<float>(b) la ham ep kieu du lieu tuc thoi b
    //tu kieu integer thanh kieu float de thuc hien phep chia
    c=static_cast<float>(b)/static_cast<float>(a);
    cout<<"c= b/a = "<<c<<endl;
    //Ngoai kieu du lieu float, co the thay the bang long, short.
    cout<<"dong 1 \n dong 2 \n dong 3 \n dong 4";
    return 0;
}
