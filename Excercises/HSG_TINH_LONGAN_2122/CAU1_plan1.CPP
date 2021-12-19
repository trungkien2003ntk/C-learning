#include <bits/stdc++.h>

using namespace std;

long long time_Counting(long long time)
{
    long long temp = 30;
    long long ans = 0;
    for (int i = 1; i <= time; i++)
    {
        ans += temp;
        if (i % 5 == 0)
            temp += 30;
    }
    return ans;
}

int main()
{
    long long time;
    cin >> time;
    cout << time_Counting(time) << endl;
    return 0;
}