#include <iostream>
using namespace std;

int main(){
    int a;
    cin >>a;
    if (a>2)
        if (a%4==0)
            cout << "YES";
        else 
            cout << "NO";
    else 
        cout << "NO";
    
    
    system("pause");
    return 0;
}