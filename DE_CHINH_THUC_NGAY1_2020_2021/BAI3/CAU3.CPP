#include <iostream>
#include <string>

using namespace std;
//functions
string dao_chuoi(string st);
bool xet_dx(string st);
void nhap();
void Cat_DMY();
void tangD();
void tangM();
void tangY();
bool Nhuan(string Y);
bool dx(string D, string M, string Y);
//bien toan cuc
string chuoi;
string D,M,Y;

void nhap(){
    getline(cin,chuoi);
}

bool Nhuan(string Y){
    int Y_num=stoi(Y);
    if (Y_num%4==0)
        return true;
    else
        return false;
}

void tangD(){
    int D_num=stoi(D);
    int M_num=stoi(M);
    if (M_num==1 || M_num==3 || M_num==5 || M_num==7 || M_num==8 || M_num==10 || M_num==12)
        if (D_num<31)
            D_num++;
        else{
            D_num=1;
            tangM();
        }
    else
        if (M_num==2)
            if (Nhuan(Y))
                if (D_num<29)
                    D_num++;
                else{
                    D_num=1;
                    tangM();
                }
            else
                if (D_num<28)
                    D_num++;
                else{
                    D_num=1;
                    tangM();
                }
        else
            if (D_num<30)
                D_num++;
            else{
                D_num=1;
                tangM();
            }
    D=to_string(D_num);
    //them so 0 neu chua du 2 ki tu
    if (D.size()<2)
        D="0"+D;
}

void tangM(){
    int M_num=stoi(M);
    if (M_num<12)
        M_num++;
    else{
        M_num=1;
        tangY();
    }
    M=to_string(M_num);
    if (M.size()<2)
        M="0"+M;
}

void tangY(){
    int Y_num=stoi(Y);
    Y_num++;
    Y=to_string(Y_num);
    //them so 0 neu chua du 4 ki tu
    switch (Y.size()){
        case 1:
            Y="000"+Y;
            break;
        case 2:
            Y="00"+Y;
            break;
        case 3:
            Y="0"+Y;
            break;
        default:
            break;
    }
}
//xet doi xung
string dao_chuoi(string st){
    string st_dao="";
    for (int i=st.size()-1;i>=0;i--)
        st_dao+=st[i];
    return st_dao;
}

bool xet_dx(string st1){
    string st_dao1=dao_chuoi(st1);
    if (st_dao1==st1)
        return true;
    else
        return false;
}

bool dx(string D, string M, string Y){
    string st=D+M+Y;
    if (xet_dx(st))
        return true;
    else
        return false;
}

void Xuli(){
    //Cat Day Month Year
    D=chuoi.substr(0,2);
    M=chuoi.substr(3,2);
    Y=chuoi.substr(6,4);
    while (!dx(D,M,Y)){
        tangD();
    }
    cout<<D<<"."<<M<<"."<<Y;
}

int main(){
    nhap();
    Xuli();
    return 0;
}