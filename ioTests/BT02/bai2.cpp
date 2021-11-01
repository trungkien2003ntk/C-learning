#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

// Khai bao bien toan cuc
string st;
int arrint[1000],arr[1000],csnt=0, cs=0;
int total;

// Khai bao tien su dung
void nhap();
void cutnum();
int sumall();
void sapxep();
void xuat();
bool ktnt();
int sumn(int x);
void xuly();
void xuatfile();


void nhap()
{
    ifstream f;
    f.open("bai2.inp");
    getline(f,st);
    f.close();
    // Xuat kiem tra
    cout << "Mang da nhap: "<< endl;
    cout << st << endl;
}

void cutnum()
{
    // Cat num dang array ra khoi chuoi
    int t;
    string stempt,num;
    stempt = st;
    while (stempt.length()>0)
    {
        while ((!isdigit(stempt[0])) && (stempt.length()>0))
            stempt.erase(0,1);
        t=0;
        while ((isdigit(stempt[t])) && (t<stempt.length()))
            t++;

        // Cat so tu chuoi va check lai
        num = stempt.substr(0,t);
        // cout << "num = " << num << endl;

        // Chen chuoi vao mang integer
        if (num != "")
            {
                cs++;
                arrint[cs] = stoi(num);
                // Check dau ra 
                // cout << cs << "-> " << arrint[cs] << endl;
            }

        
        // Reset vi tri dau bang cach xoa chuoi, reset num de kiem tra cuoi
        stempt.erase(0,t);
        num = "";
        // cout << "stempt = " << stempt << endl;
    }
}

int sumall()
{
    int kq=0;
    for (int i=1; i<=cs; i++)
        kq+= arrint[i];
    return kq;
}

void sapxep()
{
    int k;
    for (int i=1;i<cs;i++)
        for (int j=i+1;j<=cs;j++)
            if (arrint[i]>arrint[j])
                {
                    k= arrint[i];
                    arrint[i] = arrint[j];
                    arrint[j] = k;
                }
}

void xuat()
{
    total = sumall();
    cout << "Tong cac so trong mang la: " << total << endl;
    cout << "Mang sau khi sap xep la: " << endl;
    for (int i=1;i<=cs;i++)
        cout << setw(5) << arrint[i];
    cout << endl;
    cout << "Tong 3 phan tu lon nhat la: " << sumn(3) << endl;
}

int sumn(int x)
{
    int kq,i;
    kq=i=0;
    while (i<x)
        {
            kq += arrint[cs-i];
            i++;
        }
    return kq;
}

bool ktnt(int x)
{
    bool kq = true;
    if (x<2)
        kq = false;
    for (int i = 2;i<=sqrt(x);i++)
        if (x % i == 0)
            kq = false;
    return kq;
}


void xuly()
{
    for (int i=1;i<=cs;i++)
        if (ktnt(arrint[i]))
            {
                csnt++;
                arr[csnt] = arrint[i];
            }
}

void xuatfile()
{
    ofstream f;
    f.open("bai2.oup");
    f << total << endl;
    for (int i = 1;i<=cs;i++)
        f << arrint[i] << " ";
    f.close();
}


int main()
{
    nhap();
    cutnum();
    sapxep();
    xuly();
    xuat();
    xuatfile();
}
