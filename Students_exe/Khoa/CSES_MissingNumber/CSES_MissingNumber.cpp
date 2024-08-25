#include <bits/stdc++.h>
#include <vector>
using namespace std;
//============================================================================
// START PROGRAM
//============================================================================
long long n, sum = 0, tempt;
int main()
{
    cin >> n;
    sum = n * (1 + n) / 2;
    while (cin >> tempt)
        sum -= tempt;

    cout << sum;
    // getchar();
}