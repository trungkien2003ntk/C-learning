#include<iostream>

using namespace std;

int main()
{
    int n;
    int k;
    cin >>n;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=i;j++)
        {
            k+=4;
            cout <<k << " ";
        }
        cout <<endl;
    }
    return 0;
}
