#include <iostream>
#include <string>
using namespace std;

int main()
{
    int M,S;
    string max="";
    cin>>M>>S;
    int sum=0;
    if(S<=9*M)
    {
        for(int x=0;x<M;x++)
        {
            if(sum>S)
                break; 
            else
                if(S-sum>9)
                    max=max+"9";
                else
                max=max+to_string(S-sum);
                sum=sum+max[x]-48;
            if(x==M-1&&sum!=S)
                cout<<"-1";
            if(x==M-1&&sum==S)
                cout<<max<<endl;
        }
        string min="";
        if(max[max.length()-1]=='0')
                min=min+"1";
            else
                min=min+max[max.length()-1];
        int check=1;
        for(int x=max.length()-2;x>=0;x--)
        {
            if(max[max.length()-1]=='0'&&max[x]!='0'&&check==1)
            {
                check=0;
                max[x]=max[x]-1;
            }
            min=min+max[x];
        }
        cout<<min;
    }
    else
        cout<<"-1"<<" "<<-1;
    return 0;
}
//nay la chi huong giai thoi, trinh tu output em bi nguoc voi em chua lam ki~ truong hop -1 -1 anh check giup em
