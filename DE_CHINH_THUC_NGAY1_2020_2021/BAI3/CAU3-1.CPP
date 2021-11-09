#include <iostream> 
#include <string>
using namespace std; 

//functions
void nhap();
void TachDMY();
void Daonam();
bool Nhuan(int Year);
int Maxday(int Month);
bool dkchuan();
void TangY();
bool datangnam();
void xuat_ra();
//bien toan cuc
string st,D,M,Y,Dnew,Mnew;
int Dn; 
int Mn;
int Yn;
int Dnewn;
int Mnewn;
int solantangnam=0;


void nhap(){
    getline(cin,st);
}

void TachDMY(){
    D=st.substr(0,2);
    Dn=stoi(D);
    M=st.substr(3,2);
    Mn=stoi(M);
    Y=st.substr(6,4);
    Yn=stoi(Y);
}

void Daonam(){
    Dnew=""; Mnew="";
    Dnew+=Y[3]; Dnew+=Y[2];
    Mnew+=Y[1]; Mnew+=Y[0];
    Dnewn=stoi(Dnew);
    Mnewn=stoi(Mnew);
    if (dkchuan())
        if (datangnam())
            xuat_ra();
        else
            if (Mnewn>Mn)
                xuat_ra();
            else
                if(Mnewn==Mn && Dnewn > Dn)
                    xuat_ra();
                else{
                    TangY();
                    Daonam();
                }
    else{
        TangY();
        Daonam();
    }          
}

void xuat_ra(){
    cout<<Dnew<<"."<<Mnew<<"."<<Y;
}

bool Nhuan(int Year){
    if (Year%4==0)
        return true;
    else
        return false;
}

int Maxday(int Month){
    if (Month ==1 || Month==3 || Month ==5 || Month ==7 || Month ==8 || Month ==10 ||Month ==12){
        return 31;
    }
    else
        if (Month==2)
            if (Nhuan(Yn))
                return 29;
            else
                return 28;
        else
            return 30;
}

bool dkchuan(){
    if (Dnewn<=Maxday(Mnewn) && 1<=Dnewn && Mnewn>=1 && Mnewn<=12){
        return true;
    }
    else
        return false;
}

bool datangnam(){
    if (solantangnam==0)
        return false;
    else
        return true;
}

void TangY(){
    solantangnam++;
    Yn++;
    Y=to_string(Yn);
    //xu li so 0
    if (Y.length()==1)
        Y="000"+Y;
    else
        if (Y.length()==2)
            Y="00"+Y;
        else
            if (Y.length()==3)
                Y="0"+Y;
}

int main(){
    nhap();
    TachDMY();
    Daonam();
    return 0; 
}