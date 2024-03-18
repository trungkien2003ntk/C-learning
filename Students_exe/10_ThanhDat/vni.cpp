#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
     long long a[N + 1], res[N + 1] = {0};
    for (int i = 0; i < N; i++)
        cin >> a[i];
    long long amountVNI = 1, sum_boughtVNI = 0,temp=a[N-1],pos=N-1;
   // for (int x = N - 1; x >= 0; x--)
   // {
        for (int i = N-2; i >= 0; i--)
        {
            sum_boughtVNI += a[i];
            
            if (a[i] <= temp)
            {
                res[i] = max(res[i+1],temp * amountVNI - sum_boughtVNI+res[pos]);
                amountVNI++;
               // res[i]+=res[pos];
            }
            else
            {
                res[i] = max(res[i+1], max(0LL,temp * amountVNI - sum_boughtVNI));
                sum_boughtVNI = 0;
                amountVNI = 1;
                temp=a[i];
                pos=i;
              //  x = i + 1;
               // break;
            }
              for(int x=0;x<N;x++)
                  cout<<res[x]<<" ";
                  cout<<"pos"<<pos;
              cout<<endl;
        }
  //  }
    int q, k;
    cin >> q;
    // for(int x=0;x<N;x++)
    //    cout<<res[x]<<" ";
    for (int i = 0; i < q; i++)
    {
        cin >> k;
        cout << res[k - 1] << endl;
    }
}
