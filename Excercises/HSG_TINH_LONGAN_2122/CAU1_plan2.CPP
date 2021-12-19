#include <bits/stdc++.h>

using namespace std;

long long Sum(long long x, long long y)
{
    if (x == y)
        return x;
    return ((y - x + 1)) * (x + y) / 2;
}

long long time_Counting(long long time)
{
    long long remain = time % 5;
    long long div = time / 5;
    long long ans = 5 * 30 * (Sum(1, div));
    return ans + remain * 30 * (div + 1);
}

int main()
{
    long long time;
    cin >> time;
    cout << time_Counting(time) << endl;
    return 0;
}
/*
n = 7
=> time = 5 * 30 + 2*60
n=14
=> time = 5 * 30 + 5 * 60 + 4 * 90
        = 5 * (30 + 60) + 4 * 90
        = 5 * 30 * (1 + 2) + (4 * 30 * 3)

n= 21
=> time = 5* 30 * (1 + 2 + 3 + 4) + (1 * 30 * 5)

n = k
=> time = 5 * 30 * (1 + 2 + 3 + ... + k/5) + (k % 5) * 30 * (k/5+1)
*/