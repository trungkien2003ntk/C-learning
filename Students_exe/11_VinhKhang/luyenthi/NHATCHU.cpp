#include<iostream>
#include<string>

using namespace std;
//function
void nhap();
int main();

//variables
string st;
int track[123];
void nhap()
{
    getline(cin,st);
}
void xuli()
{
    fill_n(track,123,0);
    string dem="";
    for(int i=0;i<st.size();i++){
        if(track[st[i]]==0)
            dem+=st[i];
        track[st[i]]++;
    }
    cout << dem;
}

int main()
{
    nhap();
    xuli();
    return 0;
}
//Mang kieu bool danh dau
//fill_n(<array>,<so pt>,<gia tri>);
//<=>for(int i=0;i<=<so pt>;i++)
//<array>[i]=<gia tri>;
