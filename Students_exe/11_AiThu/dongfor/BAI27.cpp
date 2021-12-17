#include<iostream>

using namespace std;

int main()
{
    int n,m;
    cin >>n >>m;
    for (int i=1;i<=n*m;i++)
    {
        if (i%m==0)
            cout <<i <<endl;
        else
            cout <<i << " ";
    }
    return 0;
}
