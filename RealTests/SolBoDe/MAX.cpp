#include <iostream>
#include <fstream>


using namespace std;

int m,n,k;
int arr[1000][1000];

void nhap();

void nhap()
{
    ifstream f;
    f.open("bai5.inp");
    f >> n >> m;
    f.close();
}

int ucln(int x,int y)
{
    int a,b;
    a=x;
    b=y;
    while (a!=b)
        if (a>b)
            a-=b;
        else
            b-=a;
    return a;
}

void check()
{
    k = 0;
    int t = m;

    cout << k;
}

int main()
{
    nhap();
    check();
}
