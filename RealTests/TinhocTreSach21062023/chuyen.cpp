#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll startOfSpace, endOfSpace;

ll maxSizeAvailabeAndUpdateBoundaries(string s)
{
    vector<char> v(256, 0);
    ll left = 0, maxLenght = INT_MIN;
    for (int right = 0; right < s.size(); right++)
    {
        v[s[right]]++;

        if (v['X'] == 0)
        {
            ll temp = maxLenght;

            maxLenght = max(maxLenght, right - left + 1);

            if (maxLenght != temp)
            {
                startOfSpace = left;
                endOfSpace = right;
            }
        }
        else
        {
            left = right + 1;
            v['X'] = 0;
        }
    }
    return maxLenght;
}

vector<ll> markSpacePos(string s)
{
    vector<ll> space;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '.')
        {
            space.push_back(i);
        }
    }
    return space;
}

ll step(string s, ll target)
{
    ll space = maxSizeAvailabeAndUpdateBoundaries(s);
    ll res = 0;

    if (space == target)
    {
        return 0;
    }

    vector<ll> posOfSpace = markSpacePos(s);

    for (int i = startOfSpace - 1; i >= 0; i--)
    {
        if (s[i] == '.')
        {
            res = res + startOfSpace - i - 1;
            startOfSpace--;
            space++;
            if (space == target)
            {
                return res;
            }
        }
    }

    for (int i = endOfSpace + 1; i < s.size(); i++)
    {
        if (s[i] == '.')
        {
            res = res + i - endOfSpace - 1;
            endOfSpace++;
            space++;
            if (space == target)
            {
                return res;
            }
        }
    }

    return res;
}

int main()
{
    ll t;

    cin >> t;

    while (t--)
    {
        ll n;
        string s;

        cin >> s >> n;

        cout << step(s, n) << "\n";
    }
}