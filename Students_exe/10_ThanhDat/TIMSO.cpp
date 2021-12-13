#include <iostream>
#include <string>
using namespace std;

int main()
{
    string st;
    cin>>st;
    char chutim='Z';
    string ZERO="ZERO";
    string ONE="ONE";
    string TWO="TWO";
    string THREE="THREE";
    string FOUR="FOUR";
    int c_ZERO=0;
    int check0=0;
    for(int x=0;x<st.length();x++)
        if(st[x]==ZERO[c_ZERO])
        {
            x=0;
            check0++;
            c_ZERO++;
        }
    if(check0==4)
        cout<<"ZERO";
    int c_ONE=0;
    int check1=0;
     for(int x=0;x<st.length();x++)
        if(st[x]==ONE[c_ONE])
        {
            x=0;
            check1++;
            c_ONE++;
        }
    if(check1==3)
        cout<<"ONE";
    int c_TWO=0;
    int check2=0;
     for(int x=0;x<st.length();x++)
        if(st[x]==TWO[c_TWO])
        {
            x=0;
            check2++;
            c_TWO++;
        }
    if(check2==3)
        cout<<"TWO";
    int c_THREE=0;
    int check3=0;
    int avoid=-1;
     for(int x=0;x<st.length();x++)
     {  
        if(st[x]==THREE[c_THREE]&&x!=avoid)
        {
            
            check3++;
            if(c_THREE==3)
                avoid=x;
            x=0;
            c_THREE++;
        }
     }
    if(check3==5)
        cout<<"THREE";
    int c_FOUR=0;
    int check4=0;
     for(int x=0;x<st.length();x++)
        if(st[x]==FOUR[c_FOUR])
        {
            x=0;
            check4++;
            c_FOUR++;
        }
    if(check4==4)
        cout<<"FOUR";
    return 0;

}
