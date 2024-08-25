#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int Max_N = 1e6+10;

int A[Max_N], n;

void input() 
{
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        cin >> A[i];
    }
}

ll cnt = 0;
void sub1()
{
    sort(A, A+n);

    for (int i = 0; i < n; i++) 
    {
        int a = A[i];
        int l = 0, r = n - 1;

        while (l < r) 
        {
            int c = A[l] + A[r];
            if (c == a) 
            {
                if (l != i && r != i) 
                {
                    cnt++;
                    //cout << a << ' ' << A[l] << ' ' << A[r] << "\n";
                }
                l++; 
            } 
            else if (c < a) 
            {
                l++;
            } 
            else 
            {
                r--;
            }
        }
    }
    cout << cnt*2; 
}

void sub2()
{
    for (int i = 1; i <= n; i++)
    {
        cnt += floor((i-1)/2.0);
    }
    cout << cnt*2;
}

void solve() 
{
    if (n <= 3000) sub1();
    else sub2(); 
}

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("PTB2.INP", "r", stdin);
    freopen("PTB2.OUT", "w", stdout);
    int t = 1; //cin >> t;
    while (t--) {
        input();
        solve();
    }
}
