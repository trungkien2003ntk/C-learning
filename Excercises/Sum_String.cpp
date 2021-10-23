#include <iostream>
#include <string>
using namespace std;

int main(){
    string num1,num2;
    cin>>num1;
    cin>>num2;
    string sum,st_sum_con;
    int sum_con;
    if(num1.length()<num2.length())
        swap(num1,num2);
    //num1 luon lon hon num2
    int du=0;
    for(int x=1;x<=num1.length();x++)
    {   
        // int du;
        if(x<=num2.length())
        {    
            sum_con=(num1[num1.length()-x]-48)+(num2[num2.length()-x]-48)+du;
            du=0;
            st_sum_con=to_string(sum_con);
            if(sum_con>=10)
            {   
                if(x!=num1.length())
                {
                    du++;
                    sum_con%=10;
                    st_sum_con=to_string(sum_con);
                }
                else        //Khi cong den thang dau  tien cua num1
                {
                    int count=sum_con%10;
                    // sum_con=sum_con/10;
                    // sum_con=count*10 + sum_con%10; 
                    st_sum_con=to_string(sum_con)+"1";      // Thi du sum_con=12 thi se cong vao sum la 21
                }
            }
            //string st_sum_con=to_string(sum_con);
            sum=sum+st_sum_con;
        }   
        else{                               // Khi x vuot qua length num2 thi cong cac ki tu con lai cua num1 voi 0; 
            sum_con=(num1[num1.length()-x]-48)+du;
            du=0;
            st_sum_con=to_string(sum_con);
            if(sum_con>=10){   
                if(x!=num1.length()){       // Khi chua cong den thang dau tien cua num1;
                    du++;
                    sum_con%=10;
                    st_sum_con=to_string(sum_con);
                }
                else{
                    int count=sum_con%10;
                    // sum_con=sum_con/10;
                    // sum_con=count*10 + sum_con%10; 
                    st_sum_con=to_string(sum_con)+"1";
                }
            }
            //string st_sum_con=to_string(sum_con);
            sum=sum+st_sum_con;
        }
        // if(x==num2.length()+1)
        // {   
        //     for(int i=num1.length()-num2.length();i>0;i--)
        //     {  
        //         sum_con=(num1[i-1]-48)+du;
        //         du=0;
        //         if(sum_con>=10)
        //         {
        //             if(i!=1)
        //             {
        //                 du++;
        //                 sum_con=sum_con%10;
        //                 st_sum_con=to_string(sum_con);
        //             }
        //             else
        //             {
        //                 sum_con%=10;
        //                 st_sum_con=to_string(sum_con)+"1";
        //             }
        //         }
        //         sum=sum+st_sum_con;
        //     }
            
        // }       
    }
    //reverse so lai
    string rev_sum="";
    int i=0;
    for(int x=sum.length()-1;x>=0;x--)
    {   
        rev_sum+=sum[x];
    }
    cout<<rev_sum;
    return 0;
}

