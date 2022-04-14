#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<pair<int,int>> datRaw;
vector<set<int>> datCooked;
vector<int> tracker;
int n,m;

void nhap(){
	int x,y;
	cin >> n >> m;
	for (int i=1;i<=m;i++){
		cin >> x >> y;
		if (x>y)
			swap(x,y);
		datRaw.push_back(make_pair(x,y));
	}
	sort(datRaw.begin(),datRaw.end());
	for (int i=0;i<=n;i++)
		tracker.push_back(-1);
}

void xuly(){
	for (int i=0;i<m;i++){
		if (tracker[datRaw[i].first]==-1 && tracker[datRaw[i].second]==-1){
			set<int> tempt;
			tempt.insert(datRaw[i].second);
			tempt.insert(datRaw[i].first);
			datCooked.push_back(tempt);
			tracker[datRaw[i].first] = datCooked.size()-1;
			tracker[datRaw[i].second] = datCooked.size()-1;
			tempt.empty();
		} 
		else{
			if (tracker[datRaw[i].first] != -1 && tracker[datRaw[i].second]==-1){
				int csfind = 0;
				while (csfind != tracker[datRaw[i].first])
					csfind++;
				datCooked[csfind].insert(datRaw[i].second);
				tracker[datRaw[i].second] = tracker[datRaw[i].first];
			} else if (tracker[datRaw[i].first] == -1 && tracker[datRaw[i].second]!=-1){
				int csfind = 0;
				while (csfind != tracker[datRaw[i].second])
					csfind++;
				datCooked[csfind].insert(datRaw[i].first);
				tracker[datRaw[i].first] = tracker[datRaw[i].second];
			} else if (tracker[datRaw[i].first] != -1 && tracker[datRaw[i].second]!=-1){
				int p,q;
				if (tracker[datRaw[i].first] > tracker[datRaw[i].second]){
					p = tracker[datRaw[i].first];
					q = tracker[datRaw[i].second];
				} else {
					q = tracker[datRaw[i].first];
					p = tracker[datRaw[i].second];
				}	
//				int csfind = tracker[datRaw[i].second];
				for (auto it=datCooked[q].begin();it!=datCooked[q].end();it++)
					tracker[*it] = tracker[datRaw[i].first];
				datCooked[tracker[datRaw[i].first]].insert(tempt.begin(),tempt.end());
				datCooked.erase(datCooked.begin()+csfind,datCooked.begin()+csfind+1);
				for (int j=1;j<=n;j++)
					if (tracker[j]>=csfind)
						tracker[j]--;	
			}
		}
	}
	int addup=0;
	for (int i=1;i<=n;i++)
		if (tracker[i]==-1)
			addup++;
	cout << datCooked.size()-1+addup;
}
int main(){
	nhap();
	xuly();
	return 0;
}