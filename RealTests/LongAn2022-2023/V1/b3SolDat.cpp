#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long N, Z, M, u, K;
    int dup[200000] = {0};
    ifstream f;
    f.open("GAME.INP");
    f >> N >> Z >> M;
    for (int x = 1; x <= M; x++)
    {
        f >> u;
        dup[u]++;
    }
    f.close();
    for (int K = 1; K <= N; K++)
        if (N % K == 0 && (Z - 1) % K != 0)
            K += 0;
        else
            for (int i = 1; i <= N; i += K)
            {
                if (dup[i] == 1)
                    break;
                if (i == Z)
                {
                    cout << K;
                    return 0;
                }
                if (i + K > N)
                    i = (i + K) % N - K;
            }
}