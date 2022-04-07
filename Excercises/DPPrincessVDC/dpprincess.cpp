#include <iostream>
#include <vector>

using namespace std;

int slTest, n,result;
void xuly(vector<int> &dat,int pos,int currentTotal);

void nhapXL()
{
    cin >> slTest;
    for (int i = 0; i < slTest; i++)
    {
        cin >> n;
        vector<int> a;
        int tempt;
        for (int j = 0; j < n; j++)
        {
            cin >> tempt;
            a.push_back(tempt);
        }
        //        cout << "i= " << i << endl;
        //        for (int j=0;j<n;j++)
        //            cout << a[j] << ' ';
        //    	cout << endl;
        result = 0;
        for (int t=0;t<=n;t++)
        	xuly(a, 0, a[t]);
        cout << result << endl;
    }
}

void xuly(vector<int> &dat, int pos, int currentTotal)
{
    if (currentTotal > result)
        result = currentTotal;
    if (pos < dat.size()-1){
        for (int p = pos + 2; p < dat.size(); p++){
        	currentTotal+= dat[p];
        	xuly(dat,p,currentTotal);
        	currentTotal-= dat[p];
		}
    }
}        

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    nhapXL();
    return 0;
}