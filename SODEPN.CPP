#include <iostream>
#include <math.h>
using namespace std; 

int main()
{   int count; int number; int n; int sum=0 ; int no_first_char; int k;
    cin>>n;
    int cache=n;

    while(cache!=0){
        cache = cache/10;
        count++;        //count for the length of n
    }
    //cout<<count;
    no_first_char=n;
    for(int j=count;j>0;j=j-1)
    {  
        int powten=pow(10,j-1);
        int first_num = no_first_char / powten;   
        sum = sum + first_num;
        no_first_char = no_first_char % powten; 
        cout<<"j "<<sum<<endl;  
    }

    cout<<sum;
    system("pause");
    return(0);
}
