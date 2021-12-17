#include<iostream>

using namespace std;

int N;

void nhap()
{
    cin >>N;
}

int tinhtuoi(int x)
{
    int tuoi=2021-x;
    return tuoi;
}

int main()
{
    nhap();
    cout <<tinhtuoi(N);
    return 0;
}
