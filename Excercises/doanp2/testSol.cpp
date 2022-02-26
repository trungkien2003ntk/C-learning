#include <bits/stdc++.h>

#define ll long long
using namespace std;

class node
{
    public:
        int point,other_mark;  
};

int n;
ll result=0;
vector <node> rawData;
vector<node>::iterator it1,it2,next_item;

void nhapNop(){
    cin >> n;
    node tempt;
    ll first, last;
    for (ll i =1;i<=n; i++){
        cin >> first >> last;
        tempt.point = first; 
        tempt.other_mark = last;
        rawData.push_back(tempt);
    }       
};


void nhap(){
    ifstream f("input.inp");
    f >> n;
    node tempt;
    ll first, last;
    for (ll i =1;i<=n; i++){
        f >> first >> last;
        tempt.point = first; 
        tempt.other_mark = last;
        rawData.push_back(tempt);
    }       
    f.close(); 
};

void sort_items(){
    for (it1 = rawData.begin();it1 < rawData.end();it1++)
        for (it2 = it1+1;it2 <= rawData.end();it2++)
            if (it1->point > it2->point || (it1-> point == it2->point && it1->other_mark > it2->other_mark))
                swap(*it1,*it2);

}

void xuly(){
    for (it1 = rawData.begin()+1;it1<=rawData.end();it1++){
        if (it1 != rawData.end()){
            it2 = it1+1;
            if (it2->point >= it1->other_mark)
                result += it1->other_mark - it1->point;
            if (it2->point < it1->other_mark)
                result += it2->point - it1->point;
        } else {
            result += it1->other_mark - it1->point;
        }
    }
    cout << result;
}

int main(){
    nhap();
    sort_items();
    xuly();
    return 0;
}