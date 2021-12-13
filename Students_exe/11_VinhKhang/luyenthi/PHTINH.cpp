#include<iostream>
using namespace std;
int a,b,c;
void nhap(){
    cin>>a>>b>>c;
}
int tinh(int x,int y,int z)
{
    int kq;
    kq=(a-b)*c;
    return kq;
}
int main()
{
    nhap();
    cout<<tinh(a,b,c);
    return 0;
}
