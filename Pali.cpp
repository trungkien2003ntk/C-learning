#include <iostream>
#include <math.h>
using namespace std;

int main(){ 
    int n;int arr[15];int reverse=0;
    cout << "nhap so mang " ;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"nhap so thu "<<i+1<<" :";
        cin>>arr[i];
    }
    for(int j=0;j<n;j++){
        int temp=arr[j];
        while(temp!=0){
            int digit=temp%10;
            reverse=reverse*10+digit;
            temp=temp/10;     
        } 
        if(reverse==arr[j]){
                cout<<reverse<<endl;}
             reverse=0;
    }
    system("pause");
    return(0);
}