#include <bits/stdc++.h>
using namespace std;
void Collatz(int n)
{
    while (n != 1)
    {
        cout<<n<<" ";
        if (n%2==1)
            n = 3*n + 1;
        else
            n = n/2;
    }
    cout << n;
}
int main()
{
    int n;
    cin>>n;
    Collatz(n);
    return 0;
}
