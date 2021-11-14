#include <iostream>
using namespace std;

int n;
int d;
int arr[100000];
int arr_check[100000];// check xem so do da co xuat hien trong day~ nao chua
int carr_check=0;
int arr_ss[100000];// arr dung de so sanh cac count
int carr_ss=0;
int c=0;
int dem;

void input()
{
    for(int x=0;x<n;x++)
        cin>>arr[x];
}

bool kotrung(int n)
{
    int counttrung=0;
    for(int x=0;x<carr_check;x++)
        if(n==arr_check[x])
            counttrung++;
    if(counttrung==0)
        return 1;
    else
        return 0;
}

void xuly()
{
    
    for(int x=0;x<n;x++)
    {   
        if(kotrung(arr[x]))
        {   
            c=arr[x];
            dem=1;
            arr_check[carr_check]=arr[x];
            carr_check++;
            for(int i=0;i<n;i++)
            {
                if(arr[i]==c+d && kotrung(arr[i]))
                {
                    arr_check[carr_check]=arr[i];
                    carr_check++;
                    dem++;
                    c=c+d;
                    i=0;
                }
            }
            arr_ss[carr_ss]=dem;
            carr_ss++;
        }     
    }
    for(int x=0;x<carr_ss;x++)
        cout<<arr_ss[x]<<" ";
    cout<<endl;
    for(int x=0;x<carr_check;x++)
        cout<<arr_check[x]<<" ";
}

int max()
{
    int max=arr_ss[0];
    for(int x=1;x<carr_ss;x++)
        if(arr_ss[x]>max)
            max=arr_ss[x];
    return max;
}

int main()
{
    cin>>n;
    cin>>d;
    input();
    xuly();
    cout<<endl;
    cout<<max();
    return 0;
}
