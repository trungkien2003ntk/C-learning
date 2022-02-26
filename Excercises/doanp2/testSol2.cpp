#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;
map<int,int> segs;

void nhap(){
    ifstream f("input.inp");
    f >> n;
    ll first, last;
    for (ll i =1;i<=n; i++){
        f >> first >> last;
        if ((segs.find(first) != segs.end() && last > segs[first]) || segs.find(first) == segs.end())
            segs[first] = last;
    }       
    f.close(); 
};

void xuly(){
    ll result=0,max_num=0;
    map<int,int>::iterator it;
    for (it = segs.begin();it != segs.end();it++){
        cout << it->first << " " << it->second << endl;
        if (max_num ==0 || max_num <= it->first){
            result += it->second - it->first;
            max_num = it->second;
            cout << "Max_num -> TH1 -> " << max_num << " ;Current Result: " << result << endl;
        } else if (max_num > it->first && max_num < it->second){
            result += it->second - max_num;
            max_num = it->second;
            cout << "Max_num -> TH2 -> " << max_num << " ;Current Result: " << result << endl;
        };
    };  
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    nhap();
    xuly();
    return 0;
}