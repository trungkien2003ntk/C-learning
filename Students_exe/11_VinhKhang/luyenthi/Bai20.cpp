#include<iostream>
using namespace std;

int main()
{
    int n,j;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        for(int j=2;j<=i+1;j++)
            cout << " ";
        for(int k=i+1;k<=n;k++)
            cout << n-i;
        cout << endl;
    }
    return 0;
}
