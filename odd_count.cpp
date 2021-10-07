
#include <iostream>
using namespace std;

int main(){
    
    int arr_main[100000]; int arr_side[100000]; int n;
    bool arr_side_chk[100000];
    cout <<"Input n: " <<endl;
    cin >> n;
    cout <<"Input the array: "<< endl;
    for (int i=0; i<n; i++){
        cout << "Number "<<i+1<<": ";
        cin >> arr_main[i];
    }
    
    //set up side array:
    for (int i=0; i<n;i++){
        cout << "Yes";
    }
    


    system("pause");
    return 0;
} 

/*
#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int array[10000]; int n;int i;float x;;int count;int le;
    cout<<"Input n :";
    cin>>n;
    cout<<"Input the array: "<<endl;
    //Input array
    for(i=0;i<n;i++){ 
        cout << "Number "<< i+1 <<": ";
        cin>>array[i];
    }
    for(int i=0; i<n; i++){   //access to each elements
        count=0;
        for(int j=0; j<n; j++)  //compare that element to all elements in the array and count
            if(array[i]==array[j])
                count++;

        if(count%2==1){   //output when count is an odd number
            cout<<array[i]<<" ";
            break;
        }
    }
    system("pause");
    return(0);
}
 */