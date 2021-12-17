#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >>n;
    for (int i=n;i<2*n;i++)
    {
        for (int j=i;j<n+i;j++)
        {
            cout <<j << " ";
        }
        cout <<endl;
    }
    return 0;
}
