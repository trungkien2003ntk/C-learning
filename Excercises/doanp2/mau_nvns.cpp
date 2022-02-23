#include <iostream>
#include <map>

using namespace std;
int main(){
    int n, s, d;
    map<int, int> mp;
    map<int, int>::iterator it;
    cin >> n;
    while(n--){
        cin >> s >> d;
        it = mp.find(s);
        if(it != mp.end()){
            it->second = max(it->second, d);
        }
        else{
            mp[s] = d;
        }
    }
    it = mp.begin();
    long long sum = it->second - it->first;
    int Max = it->second;
    for(++it; it != mp.end(); ++it){
        if(it->first >= Max){
            sum += it->second - it->first;
        }
        else if(it->second > Max){
            sum += it->second - Max;
        }
        Max = max(Max, it->second);
    }
    cout << sum;
    return 0;
}