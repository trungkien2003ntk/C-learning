#include <iostream>
#include <string>

using namespace std;

bool XauDoiXung(string st){
    int len=st.length();
    string st_Dao="";              //Dao nguoc xau lai va assign vao st_Dao
    for (int i=len-1;i>=0;i--)
        st_Dao+=st[i];
    if (st_Dao == st)
        return 1;
    else    
        return 0;
}

int main(){ 
    string st;
    cin>>st;
    cout<<XauDoiXung(st)<<endl;     //1 neu st la xau doi xung , 0 neu st khong la xau doi xung
    //Thu xet dieu kien nhe
    if (XauDoiXung(st)==1)
        cout<<st<<" la xau doi xung";
    else    
        cout<<st<<" khong la xau doi xung";
    return 0;
}   