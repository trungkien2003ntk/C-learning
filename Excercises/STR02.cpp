#include <iostream>
#include <string>

using namespace std;

bool Hoa(char kt){              //1 thi la Hoa, 0 thi la Thuong
    if ( kt >='A' && kt<='Z' )
        return 1;
    else 
        return 0;
}

bool La_Chu(char kt){
    if ((kt>='a' && kt <='z') || (kt>='A' && kt <='Z'))
        return 1;
    else    
        return 0;
}

char Upcase(char kt){
    return kt+ 'A'-'a';
}

char Downcase(char kt){
    return kt+ 'a'-'A';
}



string xuli(string st){
    for (int i=st.size()-1;i>=0;i--){
        if ( !La_Chu(st[i]) && st[i] != ' ')
            st.erase(i,1);
    }
    return st;
}

void Chuan_Hoa(string st[], int Size){
    //cin string array
    for (int i=1; i<=Size; i++){
        if (i==1)
            getline(cin,st[i]);
        getline(cin,st[i]);
        st[i] = xuli(st[i]);
    }
    cout<<endl;

    //Bat dau chuan hoa
    string sti_temp; // sti_temp de luu cac st[i] vao de tien xu li hon
    for (int i=1;i<=Size;i++){
        sti_temp = st[i];

        if ( !Hoa(sti_temp[0]) ){     
            sti_temp[0] = Upcase(sti_temp[0]);
        }
        
        for (int j=1; j<sti_temp.length();j++){
            if ( sti_temp[j-1] == ' ' ){    // Neu nhu thang phia truoc sti_temp[i] la khoang trang
                if ( !Hoa(sti_temp[j]) )
                    sti_temp[j] = Upcase(sti_temp[j]);
            }
            else{
                if ( Hoa(sti_temp[j]) ) 
                    sti_temp[j] = Downcase(sti_temp[j]);
            }  
        }
          
        cout<<sti_temp<<endl;
    }
}


int main(){
    int n;
    string st[10001];
    cin>>n; 

    Chuan_Hoa(st,n);

    return 0;
}