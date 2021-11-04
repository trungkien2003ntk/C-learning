#include <iostream>
#include <fstream>


using namespace std;

int n,arr[20],ckarr[20];

void nhap()
{
    ifstream f;
    f.open("bai2_2.inp");
    f >> n;
    for (int i=1;i<=n;i++)
        f >> arr[i];
    f.close();

     // Xuat kiem tra
    //  cout << n << endl;
    //  for (int i=1;i<=n;i++)
    //     cout << arr[i] << " ";
    // cout << endl;
}

void loop()
{
    for (int i=1;i<n;i++)
        ckarr[i] = abs(arr[i]-arr[i+1]);        
    ckarr[n] = abs(arr[n]-arr[1]);
    for (int i=1;i<=n;i++)
        {
            arr[i] = ckarr[i];
            // cout << arr[i] << " ";
        }
    // cout << endl;
    
}

bool check_eq()
{
    // Trang thai day chua bang nhau la true, nguoc lai false
    // Gia su day da bang nhau -> false
    bool kq = false;
    for (int i=1;i<n;i++)
        for (int j=i+1;j<=n;j++)
            if (arr[i] != arr[j])
                kq = true;
    return kq;
}

int demlap()
{
    int loop_count=0;
    while (check_eq())
    {
        loop();
        loop_count++;
        if (loop_count >1000)
            {
                loop_count = -1;
                break;
            }
        cout << loop_count << endl;
    }
    return loop_count;   
}

void xuat()
{
    int op = demlap();
    cout << "Tong cong co " << demlap() << " lan lap.";

    // Xuat file 
    ofstream f;
    f.open("bai2.oup");
    f << op;
    f.close();
}


int main()
{
    nhap();
    xuat();
}