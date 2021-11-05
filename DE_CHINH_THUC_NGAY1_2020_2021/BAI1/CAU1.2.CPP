#include <iostream>
#include <string>

using namespace std;

int a,b,tongquediem=0;

int quediem(char kt){
    switch (kt)
    {
    case '0':
        return 6;
        break;
    case '1':
        return 2;
        break;
    case '2':
        return 5;
        break;
    case '3':
        return 5;
        break;
    case '4':
        return 4;
        break;
    case '5':
        return 5;
        break;
    case '6':
        return 6;
        break;
    case '7':
        return 3;
        break;
    case '8':
        return 7;
        break;
    case '9':
        return 6;
        break;
    default:
        return 0;
        break;
    }
}

int So_que_diem(int n){
    int tongque=0;
    string So_st=to_string(n);      //chuyển số n thành string
    for (int i=0;i<So_st.size();i++){
        tongque+=quediem(So_st[i]);
    }
    return tongque;
}

void xuli(){
    for (int i=a;i<=b;i++){
        tongquediem+=So_que_diem(i);
    }
    cout<<tongquediem;
}

void nhap(){
    cin>>a>>b;
}

int main(){
    nhap();
    xuli();
    return 0;
}
