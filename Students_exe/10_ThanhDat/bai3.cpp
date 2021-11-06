#include <iostream>
#include <string>
using namespace std;


string st;

bool isdigit(char x)
{
    if(x>='0'&&x<='9')
        return 1;
    else 
        return 0;
}

string xoacham()
{
    for(int x=st.length()-1;x>=0;x--)
        if(!isdigit(st[x]))
            st.erase(x,1);
    return st;
}

string reverse()
{   
    string rev_st="";
    for(int x=st.length()-1;x>=0;x--)
        rev_st=rev_st+st[x];
    return rev_st;
}

bool kt_rev()
{
    if(st==reverse()) //05062006
        return 1;
    else 
        return 0;
}

bool namnhuan(int num_yyyy)
{
    if(num_yyyy%4==0)
        return 1;
    else 
        return 0;
}

int monthdays(int mm,int num_yyyy)
{   
    if(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12)
        return 31;
    else
        if(mm==4||mm==6||mm==9||mm==11)
            return 30;
        else
        {
            if(namnhuan(num_yyyy))
                return 29;
            else 
                return 28;
        }
}

int main()
{   
    getline(cin,st);
    xoacham();
    string dd=st.substr(0,2);
    string mm=st.substr(2,2);
    string yyyy=st.substr(4,4);

    int num_dd=stoi(dd);
    int num_mm=stoi(mm);
    int num_yyyy=stoi(yyyy);
        do
        {   
            st="";
            num_dd++;
            if(num_dd>monthdays(num_mm,num_yyyy))
            {
                num_mm++;
                num_dd=1;
            }
            if(num_mm==13)
            {
                num_mm=1;
                num_yyyy++;
            }
            //dd06 mm 06 yyyy 2006
            string dd1=to_string(num_dd);
            if(dd1.length()<2)
                dd1="0"+dd1;
            string mm1=to_string(num_mm);
            if(mm1.length()<2);
                mm1="0"+mm1;
            string yyyy1=to_string(num_yyyy);
            switch(yyyy1.length())
            {
                case 3:
                    yyyy1="0"+yyyy1;
                    break;
                case 2:
                    yyyy1="00"+yyyy1;
                    break;
                case 1:
                    yyyy1="000"+yyyy1;
                    break;
                default:break; //co cho nay 01,02... to int thi 1,2 anh Kien chi fix lai :V con lai con lam het ehehehe
            }
            st=dd1+mm1+yyyy1;
        }
        while(!kt_rev()) ;
            dd=st.substr(0,2);
            mm=st.substr(2,2);
            yyyy=st.substr(4,4);
            cout<<dd+"."+mm+"."+yyyy;
            
    return 0;
}
