#include <iostream>
#include <map>

#define ll long long
using namespace std;

int n;
map<int, int> segs;

void nhap()
{
    cin >> n;
    int first, last;
    for (int i = 1; i <= n; i++)
    {
        cin >> first >> last;
        if ((segs.find(first) != segs.end() && last > segs[first]) || segs.find(first) == segs.end())
            segs[first] = last;
    }
};

void xuly()
{
    ll result = 0;
    int max_num = 0;
    map<int, int>::iterator it;
    for (it = segs.begin(); it != segs.end(); it++)
        if (max_num == 0 || max_num <= it->first)
        {
            result += it->second - it->first;
            max_num = it->second;
        }
        else if (max_num > it->first && max_num < it->second)
        {
            result += it->second - max_num;
            max_num = it->second;
        };
    cout << result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    nhap();
    xuly();
    return 0;
}