#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
int main()
{
    int num1,num2,numtotal;
    num1=25;
    num2=1;
    numtotal = num1+ num2;
    string st1,st2,st3,st4,sttotal;
    st1="25";
    st2="1";
    sttotal = st1 + st2;
    cout <<"So thu nhat: " << num1 << endl;
    cout <<"So thu hai: " << num2 << endl;
    //cout <<"Sum integer: " << numtotal << endl;
    //format chuyen so nguyen thanh chuoi: itoa(num,target(string),base(co so chuyen doi))
    st3 = to_string(num1);
    st4 = to_string(num2);
    cout <<"So thu nhat (string): " << st1 << endl;
    cout <<"So thu hai (string): " << st2 << endl;
    //cout <<"String total: " << sttotal << endl;
    cout <<"Sum integer: " << st3+st4 << endl;
    //Chuyen so thanh chuoi stoi (integer), stof (float - so thuc), stod (double - kieu so thuc ma bo nho gap doi)
}
