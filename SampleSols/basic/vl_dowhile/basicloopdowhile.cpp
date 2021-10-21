#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdio.h>

using namespace std;
int main()
{
    //Tao mot bien x co gia tri ngau nhien
    srand((int)time(0));
    int x=rand()%10+1;
    //Ham rand() tra ve gia tri trong doan 0 den 32767
    //cout << "Gia tri can tim: "<< x;
    //Doan so
    cout << "Chuong trinh du doan so tu 1 den 10!!!" << endl;
    cout << RAND_MAX << endl;
    int t = 0;
    do
        {
            cout << "Gia tri du doan la: ";
            cin >> t;
            if (t==x)
                {
                    cout << "Ban da doan chinh xac!!!";
                    break;
                }
            else
                if (t<x)
                    //Khoi lenh
                    {
                        cout << "Gia tri ban doan nho hon gia tri can tim!!!" << endl;
                        cout << "Vui long chon gia tri khac!!!" << endl;
                    }
                else
                    {
                        cout << "Gia tri ban doan lon hon gia tri can tim!!!" << endl;
                        cout << "Vui long chon gia tri khac!!!" << endl;
                    }

        }
    while (t != x);
    return 0;
}
