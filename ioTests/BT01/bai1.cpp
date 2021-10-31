#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
// ifstream - input file stream ; ofstream - output file stream

using namespace std;

// Bien toan cuc
int n,cs=0,savent[1000],arr[1000][1000];


void nhap()
{
    // Mo file
    ifstream f;
    f.open("bai1.inp");
    f >> n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            f >> arr[i][j];
    // Dong file
    f.close();

    // Xuat kiem tra
    cout << "n = " << setw(3) << n << endl;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
            cout << setw(4) << arr[i][j];
        cout << endl;
    }
}

// Chuong trinh tinh tong
int tota(char x)
{
    // Tra ve neu x=='a' -> tong tat ca (all), tra ve x=='i' -> duong (infinite), tra ve x=='n' -> am (negative)
    int tta,tti,ttn;
    tta=tti=ttn=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            {
                tta+=arr[i][j];
                if (arr[i][j]<0)
                    ttn += arr[i][j];
                if (arr[i][j]>0)
                    tti += arr[i][j];
            }
    if (x=='a')
        return tta;
    if (x=='i')
        return tti;
    if (x=='n')
        return ttn;
}

bool ktnt(int x)
{
    bool kt=true;
    if (x<2)
        kt=false;
    else
        for (int i=2;i<=sqrt(x);i++)
            if (x%i==0)
                kt=false;
    return kt;
}

bool checkin(int x)
{
    // Gia su chua trung voi so nao trong mang
    bool kq = false;
    for (int i=1;i<=cs;i++)
        if (savent[i]==x)
            // Da trung voi mot so nao do trong mang
            kq = true;
    return kq;
}

void buildarrnt()
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if ((ktnt(arr[i][j])) && (checkin(arr[i][j])==false))
            {
                cs++;
                savent[cs] = arr[i][j];
            }
}


void xuatmh()
{
    cout << "Tong tat ca cac so trong mang la: " << tota('a') << endl;
    cout << "Tong cac so duong la: " << tota('i') << endl;
    cout << "Tong cac so am la: " << tota('n') << endl;
    cout << "Day cac so nguyen to la: " << endl;
    for (int i=1;i<=cs;i++)
        cout << setw(5) << savent[i] << "; ";
}

void xuatfile()
{
    ofstream f;
    f.open("bai1.oup");
    f << tota('a') << endl;
    f << tota('i') << " " << tota('n') << endl;
    for (int i =1;i<=cs;i++)
        f << setw(5) << savent[i] << ";";
    f.close();

}

int main()
{
    nhap();
    buildarrnt();
    xuatmh();
    xuatfile();
    return 0;
}
