#include <iostream>

using namespace std;

long long n, a[100000], dem[10000], khoiluong[10000];

int main()
{
    // freopen("CA.INP", "r", stdin);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        khoiluong[i] = a[i];
        dem[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (khoiluong[i] > khoiluong[j])
            {
                khoiluong[i] += khoiluong[j];
                dem[i]++;
            }
            else
            {
                break;
            }
        }
    }

    int max = 0, pos = 0;

    for (int i = 0; i < n; i++)
    {
        if (max < dem[i])
        {
            max = dem[i];
            pos = i;
        }
    }

    cout << pos + 1 << "\n"
         << khoiluong[pos];
}