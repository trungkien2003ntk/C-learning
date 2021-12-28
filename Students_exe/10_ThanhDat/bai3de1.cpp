#include <iostream>
using namespace std;

int arr[7][7];
int sum=0;


void nhap()
{
    for(int x=0;x<=4;x++)
        for(int i=0;i<=4;i++)
        {
            if(x==0||i==0||x==4||i==4)
                arr[x][i]=0;
            else
                cin>>arr[x][i];
        }
}

bool ngang(int x,int i)
{
    if(arr[x][i+1]!=0&&arr[x][i+2]!=0)
        return 1;
    else
        return 0;
}
bool doc(int x,int i)
{
    if(arr[x+1][i]!=0&&arr[x+2][i]!=0)
        return 1;
    else
        return 0;
}

bool xien_phai(int x,int i)
{
    if(arr[x+1][i+1]!=0&&arr[x+2][i+2]!=0)
        return 1;
    else
        return 0;
}

bool xien_trai(int x,int i)
{
    if(arr[x+1][i-1]!=0&&arr[x+2][i-2]!=0)
        return 1;
    else
        return 0;
}

void tong()
{
    for(int x=0;x<=4;x++)
    {
        for(int i=0;i<=4;i++)
        {
            if(ngang(x,i)&&arr[x][i]!=0)
            {
                sum=arr[x][i]+arr[x][i+1]+arr[x][i+2];
                break;
            }
            if(doc(x,i)&&arr[x][i]!=0)
            {
                sum=arr[x][i]+arr[x+1][i]+arr[x+2][i];
                break;
            }
            if(xien_phai(x,i)&&arr[x][i]!=0)
            {
                sum=arr[x][i]+arr[x+1][i+1]+arr[x+2][i+2];
                break;
            }
            if(xien_trai(x,i)&&arr[x][i]!=0)
            {
                sum=arr[x][i]+arr[x+1][i-1]+arr[x+2][i-2];
                break;
            }
        }
        if(sum!=0)
            break;
    }
}

bool dem_doc(int i)
{
    int check=0;
    for(int x=1;x<=3;x++)
        if(arr[x][i]!=0)
            check++;
    if(check==2)
        return 1;
    else
        return 0;
}
int tong_doc(int i)
{
    int tempsum=0;
    for(int x=1;x<=3;x++)
        tempsum=tempsum+arr[x][i];
    return tempsum;
}

bool dem_ngang(int x)
{
    int check=0;
    for(int i=1;i<=3;i++)
        if(arr[x][i]!=0)
            check++;
    if(check==2)
        return 1;
    else
        return 0;
}

int tong_ngang(int x)
{
    int tempsum=0;
    for(int i=1;i<=3;i++)
        tempsum=tempsum+arr[x][i];
    return tempsum;
}

void xuli()
{
    for(int x=1;x<=3;x++)
        for(int i=1;i<=3;i++)
            if(arr[x][i]==0)
            {
                if(dem_ngang(x))
                {
                    arr[x][i]=sum-tong_ngang(x);
                    x=1;
                    i=1;
                }
                else
                    if(dem_doc(i))
                    {
                        arr[x][i]=sum-tong_doc(i);
                        x=1;
                        i=1;
                    }
            }
}
 void xuat()
 {
     for(int x=1;x<=3;x++)
     {
        for(int i=1;i<=3;i++)
            cout<<arr[x][i]<<" ";
        cout<<endl;
     }
 }

int main()
{
    nhap();
    tong();
    xuli();
    xuat();
    return 0;
}
