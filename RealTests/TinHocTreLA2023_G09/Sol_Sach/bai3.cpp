#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long n, k, a[10000][10000], tong = 0;
vector<long long> chunha;

int main()
{
    // freopen("BAI3.INP", "r", stdin);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> a[i][j];
            if (i == n - 1)
            {
                chunha.push_back(a[i][j]);
            }
        }
    }

    for (int i = 0; i < k; i++)
    {
        int maxN = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (maxN < a[j][i])
            {
                maxN = a[j][i];
            }
        }

        if (maxN <= *max_element(chunha.begin(), chunha.end()))
        {
            tong++;
        }

        for (int i = 0; i < chunha.size(); i++)
        {
            if (chunha[i] == *max_element(chunha.begin(), chunha.end()))
            {
                chunha[i] = 0;

                break;
            }
        }
    }

    cout << tong;
}