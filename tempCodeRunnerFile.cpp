#include <iostream>
#include <string>
using namespace std;


int main(){
    int count; int n; int arr[15];
    cout <<"Nhap so phan tu cua mang: ";
    cin >> n;
    cout <<"Nhap mang: "<<endl;

    for (int i=0; i<n; i++){
        cout <<"Number "<<i<<": ";
        cin >> arr[i];
    }
    cout << n<< "\n";
    for (int j=0;j<n;j++){
        cout << arr[j]<<endl;
    }
    cout <<"end";
    system("pause");
    return 0;
}