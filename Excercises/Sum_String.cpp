#include <iostream>
#include <string>
using namespace std;

string num1,num2;
void XuliXau(){
    int len1=num1.length();
    int len2=num2.length();
    if (len1>len2){
        for (int i=1; i<=len1-len2;i++){
            num2= "0" +num2;
        }
    }
    else{
        for (int i=1; i<=len2-len1;i++){
            num1= "0" +num1;
        }
    }
}

string Sum_Two_Nums(){
    string Sum_Temp="";
    int len1=num1.length();
    int mini_sum=0;
    int du=0;
    string st_mini_sum="";
    for (int i=len1-1;i>=0;i--){
        mini_sum=num1[i]-'0'+num2[i]-'0'+du;
        du=0;
        st_mini_sum=to_string(mini_sum);
        if (mini_sum>=10){
            if (i!=0){
                du++;
                mini_sum%=10;
                st_mini_sum=to_string(mini_sum);
            }
            else{
                st_mini_sum=to_string(mini_sum);
            }
        }
        Sum_Temp=st_mini_sum+Sum_Temp;
    }
    return Sum_Temp;
}

int main(){
    getline(cin,num1);
    getline(cin,num2);
    XuliXau(); //cho 2 string bang nhau chen so 0
    cout<<Sum_Two_Nums();
    return 0;
}