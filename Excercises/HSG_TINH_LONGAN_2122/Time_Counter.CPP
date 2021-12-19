#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

int main()
{
    auto start = high_resolution_clock::now();
    // Code want to timing the duration;
    auto finish = high_resolution_clock::now();
    duration<double> elapsed = finish - start;
    cout << fixed;
    cout.precision(2);
    cout << "Elapsed time: " << elapsed.count() << " s";
    return 0;
}