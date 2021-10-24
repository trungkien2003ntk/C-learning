#include <iostream>
// Thu vien nhap file 
#include <fstream>

using namespace std;

// Khai bao bien global
int arr[100][100],luudl[100];
bool check[100][100];
int n,row=0,col=0,cs=0,maxkq=0;

void nhapdulieu()
{
    // Nhap file
    ifstream input_file;
    input_file.open("bai2.inp3");
    input_file >> n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            input_file >> arr[i][j];
    input_file.close();
}

void kiemtradulieunhap()
{
    cout << n << endl;
    for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
                cout << arr[i][j] << ' ';
            cout << endl;
        }
}
void khoitao()
{
    // Xu ly raw file
    // Tao bang danh dau 
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (arr[i][j]==0)
                check[i][j] = true;
    
    // Kiem thu bang danh dau 
    // for (int i=1;i<=n;i++)
    //     {
    //         for (int j=1;j<=n;j++)
    //             cout << check[i][j] << ' ';
    //         cout << endl;
    //     }

}

void xuly(int x,int y)
{
    // Ben trai (x-1;y)
    if (((x-1)>0) && (check[x-1][y]==0))
    {
        //Danh dau 
        check[x-1][y] = 1;
        //Luu du lieu
        luudl[cs]++;
        if (luudl[cs]>maxkq)
            maxkq = luudl[cs];
        xuly(x-1,y);
        check[x-1][y] = 0;
        luudl[cs]--;
    }

    // Ben phai (x+1;y)
    if (((x+1)<=n) && (check[x+1][y]==0))
    {
        //Danh dau 
        check[x+1][y] = 1;
        //Luu du lieu
        luudl[cs]++;
        if (luudl[cs]>maxkq)
            maxkq = luudl[cs];
        xuly(x+1,y);
        check[x+1][y] = 0;
        luudl[cs]--;
    }
    // Phia tren (x;y-1)
    if (((y-1)>0) && (check[x][y-1]==0))
    {
        //Danh dau 
        check[x][y-1] = 1;
        //Luu du lieu
        luudl[cs]++;
        if (luudl[cs]>maxkq)
            maxkq = luudl[cs];
        xuly(x,y-1);
        check[x][y-1] = 0;
        luudl[cs]--;
    }
    // Phia duoi (x;y+1)
    if (((y+1)<=n) && (check[x][y+1]==0))
    {
        //Danh dau 
        check[x][y+1] = 1;
        //Luu du lieu
        luudl[cs]++;
        if (luudl[cs]>maxkq)
            maxkq = luudl[cs];
        xuly(x,y+1);
        check[x][y+1] = 0;
        luudl[cs]--;
    }

}




int main()
{
    nhapdulieu();
    khoitao();
    //kiemtradulieunhap();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (arr[i][j] == 1)
            {
                check[i][j] = 1;
                cs++;
                luudl[cs]++;
                if (luudl[cs]>maxkq)
                    maxkq = luudl[cs]; 
                xuly(i,j);
                check[i][j] = 0;
                luudl[cs]--;
                cs--;
            }
    cout << "Max = " << maxkq;

    return 0;
}