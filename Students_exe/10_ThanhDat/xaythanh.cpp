#include <iostream> 
#include <string>
using namespace std;
//btc
string st;
string st_ans[1000];
string st_dif[1000];

void input()
{
    getline(cin,st);
}

void xuly()
{
    int c=0;
    int valuex=0;
    int start=0;
    for(int x=valuex;x<=st.length();x++)
    {
        st_ans[c]=st.substr(start,x);
        c++;
        if(x==st.length())
        {
            start++;
            x=valuex++;
        }
    }
    st_dif[0]=st_ans[0];
    int check=0;
    int st_dif_c=1;
    for(int x=0;x<c;x++)
    {
        check=0;
        for(int i=0;i<st_dif_c;i++)
            if(st_ans[x]==st_dif[i])
                check++;
            if(check==0)
            {
                st_dif[st_dif_c-1]=st_ans[x];
                st_dif_c++;
            }
    }

    for(int x=0;x<c;x++)
        cout<<st_ans[x]<<" ";//cout con` trung`

    cout<<endl;
    for(int x=0;x<st_dif_c;x++)
        cout<<st_dif[x]<<" ";//cout ko trung`
    cout<<endl;
    cout<<st_dif_c-1;//cout cai output
}

int main()
{
    input();
    xuly();
    return 0;
}
