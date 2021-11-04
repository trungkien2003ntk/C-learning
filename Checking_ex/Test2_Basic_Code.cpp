#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int arr[1000];
int n,kq=0;
int arr_first;


void input_arr()
{
    for(int x=0;x<n;x++)
        cin>>arr[x];
}

void xuly()
{
    //int brk=1;
    int count_loop=0;   //đếm số lần lặp
    int count_bang=0;
    while(count_loop<=1000)
    {   
        count_bang=0;
        for(int x=0;x<n-1;x++)
            if(arr[x]!=arr[x+1])
               count_bang++;

        if(count_bang==0){              //Nếu không có thằng nào trong mảng khác nhau thì break khỏi vòng while, xuất kết quả
            cout<<"count_bang= "<<count_bang<<endl;
            break;
        }
        //trừ như đề bài
        arr_first=arr[0];
        for(int i=0;i<n-1;i++)
            arr[i]=abs(arr[i]-arr[i+1]);
        arr[n-1]=abs(arr[n-1]-arr_first);
        //xuất các lần lặp thử
        // for(int k=0;k<n;k++)
        //     cout<<arr[k]<<" ";
        // cout<<endl;
        
        count_loop++;//tăng đếm loop lên
        //cout<<"count_loop = "<<count_loop<<", count_bang = "<<count_bang<<endl;
        if(count_loop>1000)
        {
            kq=-1;
            break;
        }
    }
    if (kq!=-1)
        cout<<count_loop;
    else
        cout<<kq;
}

int main()
{
    cin>>n;
    input_arr();
    xuly();
    return 0;
}