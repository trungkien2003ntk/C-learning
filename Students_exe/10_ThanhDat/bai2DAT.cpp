#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string st;
string st_temp;
int arr[1000];
int carr=-1;
int k=1;
int kotrung[1000];
int arr_nt[1000];
int cnt=0;//count cua arr nguyen to
int sorted[1000];


 void nhap()
 {   
     ifstream f;
     f.open("bai2.inp");
     getline(f,st);
     f.close();
     cout<<st<<endl;
 }

bool isdigit(char x)
{
    if(x>='0'&&x<='9')
        return 1;
    else 
        return 0;
}

void khongtrung()
{   
    for(int x=0;x<carr+1;x++)
    {
        int count=0;
        for(int i=0;i<k;i++)
            if(kotrung[i]==arr[x])
                count++;
        if(count==0)
        {
            kotrung[k-1]=arr[x];
            k++;
        }   
    }
    for(int x=0;x<k-1;x++)
        cout<<kotrung[x]<<" ";
    cout<<endl;
}

void sotunhien()
{
    for(int i=0;i<st.length();i++)
    {   
        if(isdigit(st[i]))
        {
            if(!isdigit(st[i+1]) || i==st.length()-1)
            {
                st_temp=st_temp+st[i];
                carr++;
                arr[carr]=stoi(st_temp);
                st_temp="";
            }
            else
            {
                st_temp=st_temp+st[i];
            }
        }
    }
}//nay anh kien chi cutnum chu con ngu lam :()

int total()
{
    int sum=0;
    for(int x=0;x<k-1;x++)
        sum=sum+kotrung[x];
    return sum;
}

bool check_nguyento(int n)
{   
    int count=0;
    for(int x=2;x<n;x++)
        if(n%x==0)
            count++;
    if(count==0)
        return 1;
    else
        return 0;    
}

void songuyento()
{
    for(int x=0;x<k-1;x++)
        if(check_nguyento(kotrung[x]))
           {arr_nt[cnt]=kotrung[x];
            cnt++;}
    for(int x=0;x<cnt-1;x++)
        cout<<arr_nt[x]<<" ";
    cout<<endl;
}

void sort()
{   for(int x=0;x<cnt-1;x++)
        sorted[x]=arr_nt[x];
    int i=1;
    for(int x=0;x<cnt-1;x++)
    {   
        for(int x=0;x<cnt-i-1;x++)
            if(sorted[x]>sorted[x+1])
                swap(sorted[x],sorted[x+1]);
        i++;
    }
    for(int x=0;x<cnt-1;x++)
        cout<<sorted[x]<<" ";
        cout<<endl;
}

int total3()
{   
    int sum3=0;
    for(int x=cnt-1;x>=cnt-1-3;x--)
        sum3=sum3+sorted[x];
    return sum3;
}

int main()
{
    nhap();
    sotunhien();
    khongtrung();
    cout<<total()<<endl;
    songuyento();
    sort();
    cout<<total3();
    return 0;
}
