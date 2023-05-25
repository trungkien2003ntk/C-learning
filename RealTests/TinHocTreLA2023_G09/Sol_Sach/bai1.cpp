#include <iostream>
#include <string>

using namespace std;

long long n, dem = 9, sochuso = 1, tong = 0, x;

int main()
{
    cin >> n;

    while (n - dem >= 0)
    {
        n -= dem;
        tong += (dem * sochuso);
        sochuso++;
        dem = stoll(to_string(dem) + "0");
    }

    tong += (n * sochuso);

    cout << tong << "\n";

    cin >> x;

    if (x <= 9)
    {
        cout << x;
        return 0;
    }

    dem = 9;
    sochuso = 1;
    tong = 0;

    while (x - dem * sochuso >= 0)
    {
        x -= (dem * sochuso);
        tong += (dem * sochuso);
        sochuso++;
        dem = stoll(to_string(dem) + "0");
    }

    long long sodu = x % sochuso;

    if (sodu == 0)
    {
        long long sogoc = 10, vitri = x / sochuso;

        while (to_string(sogoc).size() < sochuso)
        {
            sogoc = stoll(to_string(sogoc) + "0");
        }

        for (int i = 1; i < vitri; i++)
        {
            sogoc++;
        }

        cout << to_string(sogoc)[sochuso - 1];
    }

    if (sodu != 0)
    {
        long long sogoc = 10, vitri = x / sochuso + 1;

        while (to_string(sogoc).size() < sochuso)
        {
            sogoc = stoll(to_string(sogoc) + "0");
        }

        for (int i = 1; i < vitri; i++)
        {
            sogoc++;
        }

        cout << to_string(sogoc)[sodu - 1];
    }
}