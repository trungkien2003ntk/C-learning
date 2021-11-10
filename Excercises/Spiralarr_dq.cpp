#include <iostream> 
#include <iomanip>
using namespace std; 
//function
void Zero_surround();
bool up(int i, int j);
bool down(int i,int j);
bool right(int i,int j);
bool left(int i,int j);
bool around(int i, int j);
void xuat();
void loang(int i, int j);
int maxx(int arr[1000][1000], int n);

//bien toan cuc
int n;
int arr[1000][1000];
int arr_bool[1000][1000];

void Zero_surround(){
    for (int i=0;i<=n+1;i++){
        arr_bool[i][0]=true;
        arr_bool[i][n+1]=true;
    }
    for (int j=0;j<=n+1;j++){
        arr_bool[0][j]=true;
        arr_bool[n+1][j]=true;
    }
}

bool up(int i, int j){
    if (arr_bool[i-1][j])
        return true;
    else
        return false;
}

bool down(int i,int j){
    if(arr_bool[i+1][j])
        return true;
    else
        return false;
}

bool right(int i,int j){
    if(arr_bool[i][j+1])
        return true;
    else
        return false;
}

bool left(int i,int j){
    if(arr_bool[i][j-1])
        return true;
    else
        return false;
}

bool around(int i, int j){
    if (up(i,j) && down(i,j) && left(i,j) && right(i,j))
        return true;
    else
        return false;
}

void xuat(){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++)
            if (arr[i][j]!=0)
                cout<<setw(5)<<arr[i][j];
            else
                cout<<setw(5)<<maxx(arr,n)+1;
        cout<<endl;
    }   
}

int maxx(int arr[1000][1000], int n){
    int kq=arr[1][1];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (arr[i][j]>kq)
                kq=arr[i][j];
    return kq;
}

void loang(int i, int j,string road){
    if (around(i,j))
        xuat();
    else{
        if (road=="go right")
            if (up(i,j) && left(i,j) ){
                arr[i][j]=arr[i][j-1]+1;
                arr_bool[i][j]=true;
                if (!right(i,j))
                    loang(i,j+1,"go right");
                else
                    loang(i+1,j,"go down");
            }

        if (road=="go down")
            if (up(i,j) && right(i,j)){
                arr[i][j]=arr[i-1][j]+1;
                arr_bool[i][j]=true;
                if (!down(i,j))
                    loang(i+1,j,"go down");
                else
                    loang(i,j-1,"go left");
            }

        if (road=="go left")   
            if (down(i,j) && right(i,j)){
            arr[i][j]=arr[i][j+1]+1;
            arr_bool[i][j]=true;
            if (!left(i,j))
                loang(i,j-1,"go left");
            else
                loang(i-1,j,"go up");
            }

        if (road=="go up")  
            if (down(i,j) && left(i,j)){
                arr[i][j]=arr[i+1][j]+1;
                arr_bool[i][j]=true;
                if (!up(i,j))
                    loang(i-1,j,"go up");
                else
                    loang(i,j+1,"go right");
            }
    }
}

int main(){
    cin>>n;
    arr[1][1]==0;
    arr_bool[1][1]==true;
    Zero_surround();
    loang(1,1,"go right");
    return 0; 
}