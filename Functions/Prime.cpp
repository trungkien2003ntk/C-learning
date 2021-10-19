#include <iostream>
#include <math.h>
using namespace std;

bool Prime(int x){
    int count=0;
    for (int i=2; i<round(sqrt(x));i++){        //xet tu 2 -> Can bac 2 (x)
        if (x%i==0)                             //Neu x co uoc trong khoang 2 -> Can bac 2 (x)
            count++;                            //Dem uoc
    }
    if (count==0)   
        return 1;
    else    
        return 0;
}

int main() {
    int n;
    cin>>n;
    cout<<Prime(n)<<endl;          //Neu n la prime thi output 1, neu khong thi output 0
    //                                => Function Prime(x) cho ra gia tri 0 (F) hoac 1 (T)
    if (Prime(n)==1){               
        cout<<"n la so nguyen to"<<endl;
    }
    else
        cout<<"n khong la so nguyen to"<<endl;
    system("pause");
    return 0;
}