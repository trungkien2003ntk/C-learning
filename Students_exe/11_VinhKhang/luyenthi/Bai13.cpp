#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    for(int i=1;i<=n*n;i++)
    {
        cout << setw(3) << i;
        if(i%n==0)
            cout << endl;
    }
    return 0;
}
