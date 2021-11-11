#include <iostream>
#include <string>

using namespace std;

string st,fi[100000],ls[100000];
int csfi,csls,tongso,n;


void nhap();
void trans();
void xuly();


void nhap()
{
    csfi = csls = 0;
    getline(cin,st);
    n = st.length();
    csls++;
    ls[1]=st;
    // cout << ls[1] << endl;
}

bool kiemtra(string ckst)
{
    bool kq= true;
    for (int i = 1;i<=csls;i++)
        if (ckst == ls[i])
            kq = false;
    return kq;
}

void trans()
{
    for (int i = 1;i<=csls;i++)
        {
            fi[i] = ls[i];
            ls[i] = "";
        }
    csfi = csls;
    csls = 0;
}

void xuly()
{
    string c1,c2;
    // Ban dau da co san 1 buc tuong thanh goc
    tongso = 1;
    trans();
    while (n>1)
        {
            for (int i=1; i<=csfi;i++)
            {
            c1 = fi[i].substr(1);
            c2 = fi[i].substr(0,fi[i].length()-1);
            if (kiemtra(c1))
                {
                    csls++;
                    ls[csls] = c1;
                }
            if (kiemtra(c2))
                {
                    csls++;
                    ls[csls] = c2;
                }
            }
            tongso += csls;
            n--;
            trans();
            for (int j=1;j<=csfi;j++)
                cout << fi[j] << "; ";
            cout << endl;
        }

}

void xuat()
{
    cout << tongso;
}

int main()
{
    nhap();
    xuly();
    xuat();
}