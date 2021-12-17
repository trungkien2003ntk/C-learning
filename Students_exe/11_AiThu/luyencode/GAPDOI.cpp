#include<iostream>

using namespace std;

int a,sgd=0;

void nhap()
{
    cin >>a;
}

int findsgd(int x)
{
    int sgd=2*a;
    return sgd;
}

int main()
{
    nhap();
    cout <<findsgd(a);
    return 0;
}
