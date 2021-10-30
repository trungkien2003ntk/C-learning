#include <iostream>

using namespace std;
// Chuong trinh con phan lam 2 loai: Ham va Thu tuc
// Ham (Function) -> Co tra ve gia tri, tu khoa mo dau ham: int, bool, float, long .... thuong la cac kieu du lieu
// Thu tuc -> La mot doan code chi mang tinh thuc thi theo mot quy trinh, khong tra ve gia tri. Tu khoa mo dau ham: void

// Khai bao bien toan cuc
int n;
int arr[1000],cs=0;

// Khai bao pre-use (Khai bao tien su dung)
void nhap();
bool ktnguyento(int x);
void xuatraw();
void savearr();
int sumarray();


// Cac chuong trinh con
void nhap()
{
    cout << "Nhap n: ";
    cin >> n;
}

// Ham kiem tra so x co la so nguyen to hay khong
bool ktnguyento(int x)
{
    bool kq;
    kq = true;
    for (int t=2;t<x;t++)
        if (x%t==0)
            {
                kq = false;
                break;
            }
    return kq;
}

// Thu tuc kiem tra va xuat cac so nguyen to nho hon n
void xuatraw()
{
    // Xu ly kiem tra tinh nguyen to
    cout << "Cac so nguyen to nho hon " << n << " la: "<< endl;
    for (int i=2;i<n;i++)
        if (ktnguyento(i)==true)
            cout << i << "; ";
}




// Thu tuc luu vao mang
void savearr()
{
    for (int i=2;i<n;i++)
        if (ktnguyento(i))
        {
            cs++;
            arr[cs] = i;
        }
    cout << "Mang vua luu la: " << endl;
    for (int i=1;i<=cs;i++)
        cout << arr[i] << "; ";
    cout << endl;
    cout << "Tong cac phan tu cua mang la: " << sumarray();
}

// Tinh tong cac phan tu cua mang
int sumarray()
{
    int s=0;
    for (int t=1;t<=cs;t++)
       s+=arr[t];
    return s;
}

int main()
{

    // Yeu cau nhap bang thu tuc nhap
    nhap();
    // Xuat thuan khong luu vao mang
    //xuatraw();

    // Luu vao mang
    savearr();

    return 0;
}
