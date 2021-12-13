#include<iostream>

using namespace std;
char kitu;
void nhap()
{
    cin>>kitu;
}
char kt(char x)
{
    if (x=='z')
        return 'a';
    else
        x+=1;
}
int main()
{
    nhap();
    cout << kt(kitu);
    return 0;
}
