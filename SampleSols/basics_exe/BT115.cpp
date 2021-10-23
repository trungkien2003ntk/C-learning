#include <iostream>

using namespace std;
int main()
{
    int toan,van;
    float dtb;
    cout << "Nhap diem toan: ";
    cin >> toan;
    cout << "Nhap diem van: ";
    cin >> van;
    // Ep kieu du lieu thanh kieu float de phep chia co du
    dtb = (float) (toan+van)/2;
    cout << "Diem trung binh cua ban la: " << dtb; 
    return 0;
}