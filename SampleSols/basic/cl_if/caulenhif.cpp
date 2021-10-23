#include <iostream>

using namespace std;


// Chuong trinh so sanh 2 so a b nhap vao tu ban phim
int main()
{
    int a,b;
    cout << "Nhap a, b cach nhau mot khoang trong: ";
    cin >> a >> b;
    if (a>b)
        cout << "a>b";
    else
        if (b>a)
            cout << "b>a";
        else
            cout << "a=b";
    return 0;
}
