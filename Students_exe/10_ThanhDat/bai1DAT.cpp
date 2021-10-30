#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int n,arr[1000][1000];

bool songuyento(int i)
{   
    int count=0;
    for(int x=1;x<=i;x++)
        if(i%x==0)
            count++;
    if(count==2)
        return 1;
    else 
        return 0;
} 


void nhap()
{   
    fstream f;
    f.open("bai1.inp");
    f >> n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            f >> arr[i][j];
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
            cout << setw(4) << arr[i][j];
        cout << endl;
    }
     int sum=0,sumam=0,sumduong=0,cacsont[1000],k=0,countnt=0;
     for(int i=0;i<n;i++)
     {
         for(int x=0;x<n;x++)
         {
             sum=sum+arr[i][x];
             if(arr[i][x]<0)
                 sumam=sumam+arr[i][x];
             if(arr[i][x]>0)
                 sumduong=sumduong+arr[i][x];
             if(songuyento(arr[i][x]))
             {   
                 countnt++;
                 cacsont[k]=arr[i][x];
                 k++;
             }
         }
     }
     cout<<sum<<endl;
     cout<<sumam<<endl;
     cout<<sumduong<<endl;
     cout<<countnt<<endl;
     int arrkhongtrung[1000];
     int i=1;
     for(int x=0;x<k;x++)
     {  int count=0;
        for(int k=0;k<i;k++)
            if(cacsont[x]==arrkhongtrung[k])
                count++;
        if(count==0)
        {
           arrkhongtrung[i]=cacsont[x];
           i++;
        }
     }
     for(int x=1;x<i;x++)
        cout<<arrkhongtrung[x]<<" ";
}
  

int main()
{
    nhap();
    return 0;
}
