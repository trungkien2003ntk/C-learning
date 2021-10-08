#include <iostream>
#include <string>

using namespace std;

int main(){
    int num_arr[200]; int n; int length;
    string first_string; string reverse_string;
    cout <<"Nhap so phan tu n: ";
    cin >> n;
    cout <<"Nhap mang: "<<endl;
    for (int i=0; i<n; i++){
        cout <<"Nhap so thu "<<i+1<<": ";
        cin >>num_arr[i];
    }

    for (int i=0; i<n; i++){
        first_string = to_string(num_arr[i]);
        length = first_string.length();
        reverse_string="";
        for (int j=length-1; j>=0; j--){
            reverse_string = reverse_string + first_string[j];
        }
        if ( reverse_string == first_string)
            cout <<num_arr[i]<<endl;
    }
    system("pause");
    return 0;
}