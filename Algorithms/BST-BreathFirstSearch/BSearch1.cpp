#include <bits/stdc++.h>
#include <fstream>
#include <math.h>

using namespace std;
int n, m;
int a[100000], b[100000];
void nhapFile()
{
    ifstream f("BSEARCH13.in");
    f >> n >> m;
    int tempt;
    for (int i = 0; i < n; i++)
    {
        f >> tempt;
        a[i] = tempt;
    }
    for (int i = 0; i < m; i++)
    {
        f >> tempt;
        b[i] = tempt;
    }
    f.close();
}

void nhap()
{
    cin >> n >> m;
    int tempt;
    for (int i = 0; i < n; i++)
    {
        cin >> tempt;
        a[i] = tempt;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> tempt;
        b[i] = tempt;
    }
}

int bst(int item, int left, int right)
{
    if (left <= right && item >= a[left] && item <= a[right])
    {
        int checkPoint;
        // Chi so noi suy
        if (a[right] == a[left])
            checkPoint = left;
        else
            checkPoint = left + ((float)abs(item - a[left]) / (float)abs(a[right] - a[left])) * (right - left);
        // int checkPoint = left + (right - left) / 2;

        if (a[checkPoint] == item)
            return checkPoint;
        // Neu a[checkPoint] > item tuc la item khong nam trong doan tu checkPoint -> right
        if (a[checkPoint] > item)
            return bst(item, left, checkPoint - 1);
        // Nguoc lai item nam trong doan tu checkPoint+1 -> right
        return bst(item, checkPoint + 1, right);
    }
    // Neu khong tim thay
    return -1;
}

void xuly()
{
    for (int i = 0; i < m; i++)
        if (bst(b[i], 0, n - 1) != -1)
            cout << '1';
        else
            cout << '0';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    nhapFile();
    // nhap();
    xuly();
    // cout << bst(7332,0,n-1);
}