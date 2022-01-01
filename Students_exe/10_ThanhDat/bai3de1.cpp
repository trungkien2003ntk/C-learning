#include <iostream>
using namespace std;

int arr[7][7];
int sum=0;
int tongngang=0;
int tongdoc=0;
int tongxien=0;
int arrgoc[7][7];
int arrfirst[7][7];

void nhap()
{
    for(int x=0;x<=4;x++)
        for(int i=0;i<=4;i++)
        {
            if(x==0||i==0||x==4||i==4)
                arr[x][i]=0;
            else
                cin>>arr[x][i];
            arrgoc[x][i]=arr[x][i];
            arrfirst[x][i]=arr[x][i];
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
int tong_doc(int i)
{
    int tempsum=0;
    tongdoc=0;
    for(int x=1;x<=3;x++)
        tempsum=tempsum+arr[x][i];
    tongdoc=tempsum;
    return tempsum;
}

int tong_ngang(int x)
{
    tongngang=0;
    int tempsum=0;
    for(int i=1;i<=3;i++)
        tempsum=tempsum+arr[x][i];
    tongngang=tempsum;
    return tempsum;
}
int tongxienphai()
{
    int tempsum=0;
    for(int x=1;x<=3;x++)
        tempsum=tempsum+arr[x][x];
        return tempsum;
}

int tongxientrai()
{
    int tempsum=0;
    tempsum=arr[1][3]+arr[2][2]+arr[3][1];
    return tempsum;
}

bool check()
{
    for(int x=1;x<=3;x++)
        for(int i=1;i<=3;i++)
        {
            //if(arr[x][i]<0)
             //   return 1;
            if(arr[x][i]==0||tongxientrai()!=sum||tongxienphai()!=sum)
                return 1;
        }
    return 0;
}

void tong()
{
    
    for(int x=0;x<=4;x++)
    {
        for(int i=0;i<=4;i++)
        {
                if(ngang(x,i)&&arr[x][i]!=0&&i==1)
                {
                    sum=arr[x][i]+arr[x][i+1]+arr[x][i+2];
                    break;
                }
                if(doc(x,i)&&arr[x][i]!=0&&x==1)
                {
                    sum=arr[x][i]+arr[x+1][i]+arr[x+2][i];
                    break;
                }
                if(i==1||i==3)
                {
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
        }
        if(sum!=0)
            break;
    }
    cout<<sum<<endl;
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

void xuli()
{
    for(int x=1;x<=3;x++)
        for(int i=1;i<=3;i++)
            if(arr[x][i]==0)
            {
                if(dem_ngang(x))
                {
                    if(sum-tong_ngang(x)<=0)
                        break;
                    else
                    {
                        arr[x][i]=sum-tong_ngang(x);
                        x=0;
                        i=0;
                    }
                }
                else
                    if(dem_doc(i))
                    {
                        if(sum-tong_doc(i)<=0)
                            break;
                        else
                        {
                        arr[x][i]=sum-tong_doc(i);
                        x=0;
                        i=0;
                        }
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
 void gan()
 {
     for(int x=0;x<=4;x++)
        for(int i=0;i<=4;i++)
            arr[x][i]=arrgoc[x][i];
 }

int main()
{
    nhap();
    int c=0;
        if((arrfirst[1][1]==0&&arrfirst[2][2]==0&&arrfirst[3][3]==0)||(arrfirst[1][3]==0&&arrfirst[2][2]==0&&arrfirst[3][1]==0))
        {
            while(check())
           // for(int x=0;x<=521;x++)
            {
                arrgoc[2][2]++;
                gan();
                sum=arr[2][1]+arr[2][2]+arr[2][3];
                if((arr[1][1]+arr[2][2]+arr[3][3]==sum&&tong_doc(2)==sum&&tong_ngang(2)==sum)||(arr[1][3]+arr[2][2]+arr[3][1]==sum&&tong_doc(2)==sum&&tong_ngang(2)==sum))
                    xuli();
            }
        }
        else
        {
             gan();
            tong();
             xuli();
        } 
        xuat();
    cout<<endl;
    
    return 0;
}
