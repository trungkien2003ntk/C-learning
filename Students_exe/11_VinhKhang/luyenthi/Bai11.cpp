#include<iostream>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
            cout << "*";
        cout << endl;
    }
    for(int k=i+1;k<=n-1;k++)
    {
        for(int l=n-1;l>=k;l--)
            cout << "*";
        cout << endl;
    }
    return 0;
}
