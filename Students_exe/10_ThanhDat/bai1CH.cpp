#include <bits/stdc++.h>
#include <string>
using namespace std;

string nums[9]={"ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};int cnt=0;
string st;


int main()
{
    cin>>st;
    
    for(int x=0;x<st.size();x++)
    {   
      
            if(st[x]==nums[cnt][0])
                nums[cnt].erase(0,1);
        if(nums[cnt].size()==0)
        {
            cout<<cnt+1;
            return 0;
        }
            if(x==st.size()-1&&cnt<=7)
            {
                x=-1;
                cnt++;
            }    
    }
    cout<<"KHONG";
}
