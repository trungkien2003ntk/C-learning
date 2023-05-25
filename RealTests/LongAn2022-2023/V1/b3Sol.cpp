#include <iostream>

using namespace std;

int N,Z,M,K,trap[1000];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tempt;
    cin >> N >> Z >> M;
    for (int i=1;i<=N;i++){
        cin >> tempt;
        trap[tempt]++;
    }
    K = 1;
    while (K<=N){
        long long p = N*Z%K;
        
    }

    return 0;
}