#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=n-2;j>=i-1;j--)
        {
            cout << " ";
        }
        for(int k=1;k<=i;k++)
            cout << "*";
        cout << endl;
    }
    return 0;
}
