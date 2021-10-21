#include <iostream>
#include <cstring>


using namespace std;
int main()
{
    //Khai bao bien s1, s2 kieu du lieu string
    string s1,s2,s3,comps;
    int t;
    //cout << "Nhap chuoi thu nhat: ";
    //getline(cin,s1);
    //cout << "Nhap chuoi thu hai: ";
    //getline(cin,s2);

    s1="adekbcdl";
    s2="bcd";
    s3="cpp";
    cout << "Chuoi thu nhat: " << s1 << endl;
    cout << "Chuoi thu hai: " << s2 << endl;
    cout << "Chuoi thu ba: " << s3 << endl;

    //Gan chuoi s2 cho s3
    s3=s2;
    cout << "Chuoi thu ba moi: " << s3 << endl;
    //Ghep chuoi s1 va s2 vao chuoi s3
    s3=s1 + " " + s2;
    cout << "Chuoi thu ba moi: " << s3 << endl;
    cout << "Do dai chuoi thu ba: " << s3.length() << endl;
    cout << "Vi tri bat dau cua chuoi s2 trong s1: " << s1.find(s2)<< endl;
    cout << "Vi tri bat dau cua chuoi s3 trong s2: " << s2.find(s3)<< endl;

    // Cau lenh For
    // Cu phap: for(bienchayganbanggiatrikhoidau;dieukiendung;buocnhay)
    t=s1.length(); //8
    for (int i=0;i<t;i++)
        cout << "Ki tu thu " << i << " cua chuoi la: " << s1[i] << " . " << endl;
}
