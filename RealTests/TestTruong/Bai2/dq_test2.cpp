#include <bits/stdc++.h>

using namespace std;

int n, a[5000], kq = 0;
bool a_dd[5000],asave[5000];

void nhap()
{
    ifstream f("test2.txt");
    f >> n;
    for (int i = 1; i <= n; i++)
        f >> a[i];
    f.close();
}

void xuly(int cs, int current_result)
{
    if (kq<current_result){
    	kq = current_result;
    	for (int i=1;i<=n;i++)
    		asave[i]=a_dd[i];
	}
    for (int i=cs;i<=n;i++){
    	if (a_dd[i]==0){
    		bool tracking = 1;
    		for (int j=1;j<i;j++)
    			if (a_dd[j]==1 && a[i]%a[j]!=0){
    				tracking = 0;
    				break;
				}
			if (tracking){
				a_dd[i]=1;
				xuly(i,current_result+1);
				a_dd[i]=0;
			}
		}
	}
}

int main()
{
    nhap();
    xuly(1,0);
    cout << kq << endl;
    for (int i=1;i<=n;i++)
    	if (asave[i])
    		cout << a[i] << " ";
    return 0;
}