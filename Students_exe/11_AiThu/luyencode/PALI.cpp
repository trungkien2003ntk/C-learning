#include<iostream>

using namespace std;

int arr[10000];

void nhap()
{
    int n;
    cin >>n;
    for (int i=1;i<=n;i++)
    {
        cin >>arr[i];
        cout <<arr[i];
    }
}



int main()
{
    nhap();

    return 0;
}
