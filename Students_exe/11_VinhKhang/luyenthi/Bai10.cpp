#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n-1;j++)
            cout << " ";
        for(int k=1;k<=i*2-1;k++)
            cout << "*";
        cout << endl;
    }
    return 0;
}
