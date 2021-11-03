#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Bien toan cuc
int cs[9];
unsigned long long int first,last,sum;
string allnum = "0123456789";

void khoitao()
{
    // Tao mang bat gia tri
    cs[0] = 6;
    cs[1] = 2;
    cs[5] = cs[3] = cs[2] = 5;
    cs[4] = 4;
    cs[9] = cs[6] = 6;
    cs[7] = 3;
    cs[8] = 7;
}

void nhapdlmh()
{
    cout << "Nhap gia tri dau: ";
    cin >> first;
    cout << "Nhap gia tri cuoi: ";
    cin >> last; 
}

void nhapdlfile()
{
    ifstream f;
    f.open("bai1_4.inp");
    f >> first >> last;
    f.close();
    // cout << first << endl;
    // cout << last << endl;
}

int tinhquediem(int x)
{
    string stx;
    int kq=0, chiso;
    stx = to_string(x);
    for (int i=0;i<stx.length();i++)
        {
            chiso = allnum.find(stx[i]);
            // cout << "Chi so cua " << stx[i] << " la: " << chiso << ". Gia tri la: "<< cs[chiso] << endl;
            kq += cs[chiso];
        }
    return kq;
}

void xuly()
{
    sum = 0;
    for (int i=first;i<=last;i++)
        sum += tinhquediem(i);
}

void xuat()
{
    ofstream f;
    f.open("bai1.oup");
    f << sum;
    f.close();
}

void xuatmh()
{
    cout << "Sum = " << sum;
}

int main()
{
    // nhapdlfile();
    nhapdlmh();
    khoitao();
    // cout << "Ket qua tinh so: " << tinhquediem(23);
    xuly();
    xuat();
    xuatmh();
    return 0;
}
