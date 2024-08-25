#include <bits/stdc++.h>
#include <vector>
using namespace std;
// SPEED UP
// #pragma GCC optimize("O3") //how good is this? lol
// #pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
// #pragma GCC optimize("unroll-loops")
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
//============================================================================
// START PROGRAM
//============================================================================
long long n, res = 0, limit = 9876543210, indicator = 0, freeNum, tempt, mul, maxMul = 8;
string s;
set<char> dif;

// 1 chữ số:
// Số có 1 chữ số thoả ycdb: 1 số

// 5 chia hết cho 5, 1-> 9 9 số đôi một khác nhau.
// Số có 2 chữ số thoả ycdb: a0 -> 9, a5 -> 8 => 17 số
// All to this: 18

// 2 chữ số:
// số có 2 chữ số thoả ycdb: ab0 -> 9*8=72, ab5 -> 8*8=64 => 136 số
// All to this: 154

// 3 chữ số:
// Số có 3 chữ số thoả ycdb: abc0 -> 9*8*7=504, abc5 -> 8*8*7=448 => 952 số
// All to this: 1106

// 4 chữ số:
// Số có 4 chữ số thoả ycdb: abcd0 -> 9*8*7*6=3024, abcd5 -> 8*8*7*6=2688 => 5712
// All to this: 6818

// 5 chữ số:
// abcde0: 9*8*7*6*5=15120, abcde5: 8*8*7*6*5=13440 => 28560
// All to this 35378

// 6 chữ số:
// => 114240 (mul by 4)
// All to this: 149618

// 7 chữ số:
// => 342720 (mul by 3)
// All to this: 492338

// 8 chữ số:
// => 685440 (mul by 2)
// All to this: 1177778

// 9 chữ số:
// => 685440 (mul by 1)
// All to this: 1863218

vector<long long> dat({0, 1, 18, 154, 1106, 6818, 35378, 149618, 492338, 1177778, 1863218});

int main()
{
    fast_io;
    // 9876543210
    cin >> n;
    if (n >= 9876543210)
        cout << dat[10];
    else
    {
        // n = 7714356 -> 7 chữ số
        s = to_string(n);
        res = dat[s.length() - 1];
        // 74132
        // có tổng từ 1 -> 999999
        // Cần tính từ 1000000 -> 7714356
        // Néu só bắt đàu bằng 1,2,3,4,5,6: 1abcde0, 1abcde5 -> (6*2-1)*8*7*6*5*4 =
        // Néu só cuói là 7: 7abcdef: a thuộc 0,1,2,3,4,5,6: 71abcd0,71abcd5 -> 7*2*7*6*5*4
        // Só sẽ là: 76abcde -> 760bcd5 -> 6*5*4

        // cout << res << "\n";

        freeNum = s.length() - 2;
        tempt = 1, mul = 8;
        for (int i = freeNum; i > 0; i--)
            tempt *= (mul--);
        cout << tempt << "\n";
        if (s[indicator] <= '5')
            tempt *= (s[indicator] - '0' - 1) * 2;
        else
            tempt *= (s[indicator] - '0' - 1) * 2 - 1;
        res += tempt;

        while (indicator < s.length() - 2)
        {
            freeNum--, maxMul--;
            tempt = 1, mul = maxMul;
            indicator++;

            for (int i = freeNum; i > 0; i--)
                tempt *= (mul--);
            if (s[indicator] <= '5')
                tempt *= (s[indicator] - '0' - 1) * 2 + 1;
            else
                tempt *= (s[indicator] - '0' - 1) * 2;

            res += tempt;
        }

        // Xử lý đối với số cuói cùng
        for (long long i = 0; i < s.length() - 1; i++)
            dif.insert(s[i]);
        if (dif.size() == s.length() - 1)
            if (dif.find('0') == dif.end() && s[s.length() - 1] >= '0')
                res++;
            else if (dif.find('5') == dif.end() && s[s.length() - 1] >= '5')
                res++;
    }
    cout << res;
    // getchar();
}