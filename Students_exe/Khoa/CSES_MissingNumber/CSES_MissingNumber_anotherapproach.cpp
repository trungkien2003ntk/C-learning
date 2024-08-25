#include <bits/stdc++.h>
#include <vector>
using namespace std;

//============================================================================
// START PROGRAM
//============================================================================
long long n, tempt;
bool checker[200008];
int main()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> tempt;
        checker[tempt] = true;
    }
    for (int i = 1; i <= n; i++)
        if (checker[i] == false)
        {
            cout << i;
            break;
        }
    // getchar();
}