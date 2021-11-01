#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;
//tien khai bao
void nhap();
int max_arr(int arr[],int Size);
void Zero_surrounded();
bool dkloang(int i, int j);
bool check(char kt, int i, int j);
void xuly();
void xuat();
bool check_stop(int i, int j);
//danh sach bien
int n,arr[1000][1000]; //dau vao
int max_lo;//dau ra
int arr_bool[1000][1000],counts[1000],cs_count=0,count_temp;//xu li


//start
int max_arr(int arr[],int Size){
    int max_temp=arr[1];
    for (int i=1;i<=Size;i++)
        if (max_temp<=arr[i])
            max_temp=arr[i];
    return max_temp;
}
void nhap(){
    ifstream f;
    f.open("BAI2.INP");
    f>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++){
            f>>arr[i][j];
            if (arr[i][j]==0)
                arr_bool[i][j]=1;
            else 
                arr_bool[i][j]=0;
        }
    f.close();
}
bool check_stop(int i, int j){
    if (arr_bool[i][j]==arr_bool[i+1][j]==arr_bool[i-1][j]==arr_bool[i][j+1]==arr_bool[i][j-1]==1)  
        return true;            //neu tai vi tri do va xung quanh no deu da xet qua roi thi dung loang lai
    else    
        return false;
}
void Zero_surrounded(){
    for (int i=0;i<=n+1;i++)
        arr[i][0]=0;
    for (int j=0;j<=n+1;j++)
        arr[0][j]=0;
}
bool dkloang(int i, int j){
    if (arr[i][j]==1 && arr_bool[i][j]==false)
        return true;
    else 
        return false;
}

bool check(char kt, int i, int j){
    bool kq=false;
    switch (kt)
    {
    case 'r':
        if (dkloang(i,j+1))
            kq=true;
        break;
    case 'l':
        if (dkloang(i,j-1))
            kq=true;
        break;
    case 'u':
        if (dkloang(i-1,j))
            kq=true;
        break;
    case 'd':
        if (dkloang(i+1,j))
            kq=true;
        break;
    
    default:
        break;
    }
    return kq;
}

void loang(int i, int j){
    arr_bool[i][j]=true;
    bool stop=0;
    //cout<<i<<' '<<j<<endl;
    if (!stop){
        if (check_stop(i,j))
            stop=1;
        if (check('u',i,j)){
            count_temp++;
            loang(i-1,j);
        }
        if (check('r',i,j)){
            count_temp++;
            loang(i,j+1);
        }
        if (check('l',i,j)){
            count_temp++;
            loang(i,j-1);
        }
        if (check('d',i,j)){
            count_temp++;
            loang(i+1,j);
        }
    }
}

void xuly(){
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++){
            if (arr[i][j]==1 && arr_bool[i][j]==0){     //Neu tai o do =1 va chua xet qua
                cs_count++;
                count_temp=0;
                loang(i,j);
                counts[cs_count]=count_temp;
            }
        }
    max_lo=max_arr(counts,cs_count);
}

void xuat(){
    ofstream f;
    f.open("BAI2.OUP");
    f<<max_lo+1;
    f.close();
}

int main(){
    nhap();
    Zero_surrounded(); //pack the array by 0
    xuly();
    xuat();
    return 0;
}