#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;
int n,cs=0,cacsnt[1000],arr[100][100];
bool ktnt(int x)
{
    bool kt=true;
    if(x<2)
        kt=false;
    else{
        for (int k=2;k<=sqrt(x);k++)
            if(x%k==0)
                kt=false;}
    return kt;
}
bool checkin(int x)
{
     bool kq = false;
    for (int i=1;i<=cs;i++)
        if (cacsnt[i]==x)
            kq = true;
    return kq;
}
void nhap()
{
    fstream f;
    f.open("bt1.inp.cpp");
    f>>n;
    for (int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        f>>arr[i][j];
    f.close();
    cout << n<< endl;
    for (int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout << setw(2)<< arr[i][j];
        cout << endl;
    }
    int sum=0;
    for (int i=1;i<=n;i++){
         for(int j=1;j<=n;j++)
            sum+=arr[i][j];
    }
     cout << sum<< endl;
    int sumduong=0;
    int sumam=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr[i][j] >0)
                sumduong+=arr[i][j];
            if (arr[i][j]<0)
                sumam+=arr[i][j];
        }

    }
    cout << sumduong<<endl;
    cout << sumam<<endl;

    for (int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if ((ktnt(arr[i][j])) && (checkin(arr[i][j])==false)) {
        cs++;
        cacsnt[cs]=arr[i][j];
    }
    for (int x=1;x<=cs;x++)
        cout << setw(4) << cacsnt[x]<< "; ";
}


int main()
{
    nhap();
    return 0;
}
