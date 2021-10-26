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
                check[i][j] = false;
    
    // Kiem thu bang danh dau 
    // for (int i=1;i<=n;i++)
    //     {
    //         for (int j=1;j<=n;j++)
    //             cout << check[i][j] << ' ';
    //         cout << endl;
    //     }

}

// x,y: la dong va cot
int xuly(int x, int y)
{   
    int pending_counter=1;
    cout << "(x;y)= (" << x << "; " << y << ")"<< endl;
    // Tinh toan dien tich dat    

    if ((arr[x-1][y]==1) && (x-1>0) && (check[x-1][y]==false))
    {
        check[x-1][y] = true;
        pending_counter += xuly(x-1,y);   
        cout << "TH1: " << pending_counter << "<-> (x;y) = (" << x-1 << "; " << y << ")" << endl;
    }

    if ((arr[x+1][y]==1) && (x+1<=n) && (check[x+1][y]==false))
    {
        check[x+1][y] = true;
        pending_counter += xuly(x+1,y);   
        cout << "TH2: " << pending_counter << "<-> (x;y) = (" << x+1 << "; " << y << ")" << endl;
    }

    if ((arr[x][y-1]==1) && (y-1>0) && (check[x][y-1]==false))
    {
        check[x][y-1] = true;
        pending_counter += xuly(x,y-1);   
        cout << "TH3: " << pending_counter << "<-> (x;y) = (" << x << "; " << y-1 << ")" << endl;
    }

    if ((arr[x][y+1]==1) && (y+1<=n) && (check[x][y+1]==false))
    {
        check[x][y+1] = true;
        pending_counter += xuly(x,y+1);   
        cout << "TH4: " << pending_counter << "<-> (x;y) = (" << x << "; " << y+1 << ")" << endl;
    }

    return pending_counter+1;

    // Tra danh dau 
    if ((arr[x-1][y]==1) && (x-1>0) && (check[x-1][y]==true))
        check[x-1][y] = false;  

    if ((arr[x+1][y]==1) && (x+1<=n) && (check[x+1][y]==true))
        check[x+1][y] = false;
    
    if ((arr[x][y-1]==1) && (y-1>0) && (check[x][y-1]==true))
        check[x][y-1] = false;
 
    if ((arr[x][y+1]==1) && (y+1<=n) && (check[x][y+1]==true))
        check[x][y+1] = false;
         
}




int main()
{
    nhapdulieu();
    khoitao();
    // kiemtradulieunhap();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if ((arr[i][j]==1) && (maxkq < xuly(i,j)))
                maxkq = xuly(i,j);
    cout << "Max = " << maxkq;
    
    return 0;
}