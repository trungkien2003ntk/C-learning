#include <iostream>
#include <string>

using namespace std;

int main()
{
    // BT: Cho mot chuoi bao gom chu va so va khoang trang.
    // Cat het tat ca cac so trong chuoi do.
    // Sau do xuat cac so nay ra man hinh.
    // Hay luu cac so vao 1 mang. Tinh tong cac so nay.
    string tongs,st,s;
    int n,k,tongi;
    // Kieu mang
    string arr[100];
    int arrint[100];
    // Yeu cau nhap chuoi
    cout << "Nhap chuoi st: ";
    getline(cin, st);

    //cout << "Chuoi da nhap la: " << st << endl;
    k=0;
    n=-1;
    while (st.size()>0)
    {
        // !(isdigit(st[0])) - Khi st[0] khong la mot chu so
        while ((!(isdigit(st[0]))) && (st.size()>0))
            st = st.erase(0,1);
        while ((isdigit(st[k])) && (st.size()>0))
            k++;
        s = st.substr(0,k);
        n++;
        arr[n] = s;
        // cout << s << endl;
        st = st.erase(0,k);
        k=0;
    }
    cout << "Tat ca cac so trong chuoi la: ";
    for (int i=0;i<=n;i++)
        cout << arr[i] << "; ";
    for (int i=0;i<=n;i++)
        // Syntax ham string to integer stoi(chuoistring,vitribatdaucuachuoidoithanhso,cosochuyen)
        arrint[i] = stoi(arr[i],0,10);
    cout << endl;
    cout << "Tat ca cac so trong chuoi (dang int) la: ";
    for (int i=0;i<=n;i++)
        cout << arrint[i] << "; ";
    cout << endl;
    tongs="";
    tongi=0;
    for (int i=0;i<=n;i++)
    {
        tongs+=arr[i];
        tongi+=arrint[i];
    }
    cout << "Tong dang string: " << tongs << endl;
    cout << "Tong dang integer: " << tongi << endl;
    return 0;
}
