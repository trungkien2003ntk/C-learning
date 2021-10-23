#include <iostream>
#include <string>

//Chuong trinh xu ly chuoi
using namespace std;

int main()
{
    string st1,st2,st,st3,st4,st5;
    char k;
    int pos;
    st1 = "Nguyen Thanh Dat";
    st2 = "ank ";
    st4 = "ank";
    st5 = "nk";
    st3 = "xy";
    //Ki tu thi chi dc nam trong cap dau nhay don ' '
    k = 't';
    //Truy xuat the tung vi tri ki tu
    for (int i=0;i<=st2.size();i++)
        cout << st2[i] << endl;
    cout << st1[3] <<endl;
    // Co the dung st1.size() hoac st1.length() tuy y.
    // length duoc dinh nghia trong cstring, cstring dc bao ham trong string
    cout << st2.size() << endl;
    cout << st1.size() << endl;

    // Cong hai chuoi
    st = st1+st2;
    cout << "Chuoi gop st1 va st2: " << st << endl;

    // Tim chuoi nay trong chuoi kia
    pos = st2.find(k);
    // ngon ngu C++ la case sensitive
    cout << "Vi tri cua ki tu k trong chuoi st1: " << pos << endl;
    // Trong truong hop khong tim thay kq tra ve la -1
    // Trong truong hop tim thay thi kq tra ve la vi tri cua ki tu trong chuoi

    pos = st1.find(st2);
    cout << "Vi tri cua chuoi st2 trong chuoi st1: " << pos << endl;

    //Lay chuoi con tu mot chuoi ban dau
    //Tim ho cua mot nguoi tu mot chuoi ho ten day du
    int n=0;
    while (st1[n]!=' ')
        n++;
    cout << "Vi tri cuoi cung cua ho la: "<<n << endl;
    // Cat ho ra bang lenh substr
    string ho;
    ho = st1.substr(0,n);
    cout << "Ban nay ho: " << ho << endl;

    // Cat ten ra
    string ten;
    n=st1.size()-1;
    while (st1[n]!=' ')
        n--;
    ten = st1.substr(n,st1.size());
    cout << "Ban nay ten: " << ten << endl;

    //So sanh
    if (st4==st3)
        cout << "Chuoi st4 trung voi chuoi st3."<< endl;
    else
        cout << "Chuoi st4 khong trung voi chuoi st3. "<< endl;
    if (st5==st4)
        cout << "Chuoi st5 trung voi chuoi st4." << endl;
    else
        cout << "Chuoi st5 khong trung voi chuoi st4. " << endl;
    if (st2==st4)
        cout << "Chuoi st2 trung voi chuoi st4." << endl;
    else
        cout << "Chuoi st2 khong trung voi chuoi st4. " << endl;

    // Phuong thuc xoa; str.erase(vitribatdau); hoac str.erase(vitribatdau,sokituxoa);
    st1 = st1.erase(3,1);
    cout << "Chuoi st1 moi: " << st1 << endl;
    // Phuong thuc chen str.insert(vitrichen,kituchen/chuoichen);
    st1 = st1.insert(6,st2);
    cout << "Chuoi st1 moi: " << st1 << endl;
    // Phuong thuc thay the str.replace(vitribatdau,sokitucanthaythe,chuoithaythe)
    string s = "tk";
    st1 = st1.replace(6,3,s);
    cout << "Chuoi st1 moi: " << st1 << endl;

    return 0;
}
