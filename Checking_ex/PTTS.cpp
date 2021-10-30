#include <iostream>
using namespace std;

int main(){
    unsigned long long n;
    int arr[200];int count;int x=0;int count_arr=-1;int count_j=0;int DEM[200];int temp_DEM;int final_count;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        count=0;
        for(int x=1;x<=i;x++)
        {
            if(i%x==0)
                count++;   
        }
        if(count==2 && n%i==0)
            {count_arr++;
            arr[count_arr]=i; }          
    } 
    //   for(int x=0;x<=count_arr;x++)
     //     cout<<arr[x]<<" ";
        int j=0;
    while(n>1)
    {   
        if(n%arr[j]==0){
            n=n/arr[j];
            DEM[count_j]=arr[j];
            j--;  
            count_j++;
       }     
     j++;
     }
    for(int x=0;x<count_arr+1;x++)
    {   final_count=0;
        for(int j=0;j<count_j;j++)
        {
            if(arr[x]==DEM[j])
            final_count++;
        }
        cout<<arr[x]<<" "<<final_count<<endl;
    }
system("pause");
return(0);
}