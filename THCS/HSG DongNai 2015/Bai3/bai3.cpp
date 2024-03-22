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
int ch[208], sig, res = 0;
string s;
bool typeMark[5];
int main()
{
	fast_io;

	// Setup
	// Set a->z thuộc điều kiện số 1
	for (int it = 'a'; it <= 'z'; it++)
		ch[it] = 1;
	// Set 'A' -> 'Z' thuộc điều kiện 2
	for (int it = 'A'; it <= 'Z'; it++)
		ch[it] = 2;
	// Set '0' -> '9' thuộc điều kiện 3
	for (int it = '0'; it <= '9'; it++)
		ch[it] = 3;
	// Set các ký hiệu !;@;#;$ thuộc điều kiện 4
	ch['!'] = ch['@'] = ch['#'] = ch['$'] = 4;
	// INPUT AND OUTPUT FILES - COMMENT OUT FOR STDIN AND STDOUT
	// freopen("CAU3.INP", "r", stdin);
	// freopen("CAU3.OUT", "w", stdout);

	while (cin >> s)
	{
		sig = 10;
		for (int i = 0; i < 5; i++)
			typeMark[i] = false;
		for (auto it : s)
		{
			if (!typeMark[ch[it]])
				typeMark[ch[it]] = true, sig -= ch[it];
			if (!sig)
			{
				res++;
				break;
			}
		}
	}

	cout << res;

	//     getchar();
}