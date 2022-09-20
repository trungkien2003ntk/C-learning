#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int N;
    cin >> N;
    long long a[N + 1], res[N + 1] = {0};
    for (int i = 0; i < N; i++)
        cin >> a[i];

    long long amountVNI = 1, sum_boughtVNI = 0, temp = a[N - 1];
    for (int i = N - 2; i >= 0; i--)
    {
        sum_boughtVNI += a[i];
        res[i] = max(res[i], temp * amountVNI - sum_boughtVNI);
        if (temp * amountVNI - sum_boughtVNI > 0)
            amountVNI++;
        else
        {
            sum_boughtVNI = 0;
            amountVNI = 1;
            temp = a[i];
        }
    }

    int q, k;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> k;
        cout << res[k - 1] << endl;
    }
}