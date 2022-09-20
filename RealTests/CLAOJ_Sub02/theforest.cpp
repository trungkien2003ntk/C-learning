#include <iostream>
#include <map>
#include <vector>

using namespace std;

int n,k;
vector<vector<int>> days;
map<pair<int,int>,int> howfar;
map<int,int> result;

// Input
//6 2
//1 3
//2 1
//1 0
//2 1
//2 1
//1 5

// Output
//3
//2


void nhap(){
	days.reserve(100000);
    int x,y;
    // n: so thanh pho; k: so ngay
    cin >> n >> k;
    
    vector<int> tempt;
    for (int i=1;i<=n;i++)
    	days.push_back(tempt);
    
    for (int i=1;i<=n;i++){
        cin >> x >> y;
        if (y!=0){
        	howfar[make_pair(i,y)] = 1;
        	howfar[make_pair(y,i)] = 1;
		}
		days[x-1].push_back(i);
        result[x-1] = 0;
    }
}

void xuly(){
	for (int i=0;i<n;i++)
		for (int j=i+1;j<=n;j++)
			for (int k=1;k<=n;k++)
				if (howfar[make_pair(i,k)] && howfar[make_pair(k,j)] && (howfar[make_pair(i,j)]==0 || howfar[make_pair(i,j)]>howfar[make_pair(i,k)] + howfar[make_pair(k,j)])){
					howfar[make_pair(i,j)] = howfar[make_pair(i,k)] + howfar[make_pair(k,j)];
					howfar[make_pair(j,i)] = howfar[make_pair(i,j)];
//					cout << i << " - " << j << " -> " << howfar[make_pair(i,j)] << endl;
				}
	for (int i=0;i<k;i++)
		for (int first_city = 0;first_city < days[i].size();first_city++)
			for (int second_city = first_city+1;second_city!=days[i].size();second_city++)
				if (howfar[make_pair(days[i][first_city],days[i][second_city])] > result[i])
					result[i] = howfar[make_pair(days[i][first_city],days[i][second_city])];
	for (int i=0;i<k;i++)
		cout << result[i] << endl;
}

int main(){
    nhap();
    xuly();
    return 0;
}