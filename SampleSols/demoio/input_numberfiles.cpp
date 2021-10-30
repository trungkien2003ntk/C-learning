#include <iostream>
#include <fstream>
// 2 thu vien de lay current working path

#include <unistd.h>


using namespace std;

int main()
{
    // Dia chi mac dinh la dia chi luu file tao bai lam luon. rat tien loi.

    //char cr_path[256];
    //getcwd(cr_path,256);
    //cout << "Dia chi mac dinh: " << cr_path;

    ifstream f;
    f.open("bai2.inp");
    int n;
    int arr[100][100];
    f >> n;
    cout << "n= " << n << endl;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            {
                f >> arr[i][j];
                //cout << "a[" << i << "," << j << "]= " << arr[i][j] << endl;
            }
    f.close();
    for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
                cout << arr[i][j] << ' ';
            cout << endl;
        }
    ofstream fo;
    fo.open("bai2.out",ios::out);
    fo << "n= " << 10*n;
    fo.close();
}
