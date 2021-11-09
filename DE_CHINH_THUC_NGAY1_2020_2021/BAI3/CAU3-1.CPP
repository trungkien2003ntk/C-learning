#include <iostream> 
#include <string>
using namespace std; 
//function
void nhap();
void tachDMY();
void Daonam();
bool Nhuan(string Year);
int Maxday(int Month);
bool datangY();
void xuat();
void TangY();
bool dkchuan();
void xuli();
//bien toan cuc
string st,D,M,Y,Dnew="",Mnew="";
int D_n; 
int M_n;
int Dnew_n;
int Mnew_n;
int countupY=0; //Đếm nếu năm tăng bao nhiêu lần thì countY bằng bấy nhiêu

void nhap(){
    getline(cin,st);
}

void tachDMY(){
    D=st.substr(0,2);
    D_n=stoi(D);

    M=st.substr(3,2);
    M_n=stoi(M);

    Y=st.substr(6,4);
}

void Daonam(){
    Dnew=""; Mnew="";
    Dnew+=Y[3]; Dnew+=Y[2];
    Mnew+=Y[1]; Mnew+=Y[0];
    if (dkchuan())
        if (datangY())
            xuat();
        else
            if (Mnew_n>M_n)
                xuat();
            else 
                if (Mnew_n == M_n && Dnew_n>D_n)
                    xuat();
                else{
                    TangY();
                    Daonam();
                }
    else{
        TangY();
        Daonam();
    }
}

bool Nhuan(string Year){
    int Year_n=stoi(Year);
    if (Year_n%4==0)
        return true;
    else 
        return false;
}

int Maxday(int Month){
    if (Month==1 || Month==3 || Month==5 ||Month==7 ||Month==8 ||Month==10 ||Month==12){
        return 31;
    }
    else
        if (Month==2){
            if (Nhuan(Y)){
                return 29;
            }
            else
                return 28;
        }
        else
            return 30;
}

bool datangY(){
    if (countupY==0)
        return false;
    else
        return true;
}

void xuat(){
    cout<<Dnew<<"."<<Mnew<<"."<<Y;
}

void TangY(){
    int Y_n=stoi(Y);
    Y_n++;
    Y=to_string(Y_n);
    if (Y.size()==3){
        Y="0"+Y;
    }
    else 
        if (Y.size()==2){
            Y="00"+Y;
        }
        else 
            if (Y.size()==1)
                Y="000"+Y;
    countupY++;
}

bool dkchuan(){
    Dnew_n=stoi(Dnew);
    Mnew_n=stoi(Mnew);
    if (1<=Dnew_n && Dnew_n<=Maxday(Mnew_n) && 1<=Mnew_n && Mnew_n<=12){
        return true;
    }
    else    
        return false;
}

void xuli(){
    nhap();
    tachDMY();
    Daonam();
}

int main(){
    xuli();
    return 0; 
}