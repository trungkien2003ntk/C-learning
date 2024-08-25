#include <bits/stdc++.h>

using namespace std;

// bool la kieu du lieu dung sai - Nhan gia tri true false
bool tinHieu;
long long a,b,c;

int main() {
	tinHieu = true;
//	Lap voi so lan khong biet truoc la bao nhieu, cho toi khi nao dieu kien khong con duoc thoa nua thi dung lai
	while (tinHieu == true) { // == la so sanh; = la gan du lieu cho bien
		cout << "Nhap a= ";
		cin >> a;
		cout << "Nhap b= ";
		cin >> b;
		cout << "Nhap c= ";
		cin >> c;
		cout << "Tong a + b + c = " << a + b + c << endl; // Endl la tin hieu xuong dong sau khi xuat dong nay
		// Kiem tra coi nguoi dung co muon tinh tiep cho bo so a, b, c khac khong??
		cout << "Ban co muon tinh tiep khong (1-True/0-False)?? : ";
		cin >> tinHieu;
	}
	return 0;
}