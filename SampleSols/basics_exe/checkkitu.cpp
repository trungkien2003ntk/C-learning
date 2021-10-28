#include <iostream>
#include <string>

using namespace std;

int arr[26];
string s;

void nhap()
{
    cout << "Nhap chuoi: ";
    getline(cin,s);
}

int reasc(char x)
{
    if (int(x)<95)
        return (int(x)+32-96);
    else
        return (int(x)-96);
}

void xuly()
{
    int t;
    for (int i=0;i<s.length();i++)
        arr[reasc(s[i])]++;
}

void xuatkq()
{
    int test,ck;
    char kitu;
    cout << "Nhap so lan kiem tra: ";
    cin >> test;
    while (test>0)
    {
        cout << "Input kitu: ";
        cin >> kitu;
        cout << "Ki tu can tim lap " << arr[reasc(kitu)] << " lan trong chuoi nhap ban dau. " << endl;
        test--;
    }
}

int main()
{
    nhap();
    xuly();
    xuatkq();
    return 0;
}
