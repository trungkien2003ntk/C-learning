#include <iostream>
#include <fstream>
#include <iomanip>
// ifstream - input file stream ; ofstream - output file stream

using namespace std;

// Bien toan cuc
int n,arr[1000][1000];

void nhap()
{
    fstream f;
    f.open("bai1.inp");
    f >> n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            f >> arr[i][j];

    // Xuat kiem tra
    cout << "n = " << setw(3) << n << endl;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
            cout << setw(4) << arr[i][j];
        cout << endl;
    }
}



using namespace std;

int main()
{
    nhap();
    return 0;
}
