#include<iostream>
using namespace std;
char viethoa( char kitu)
{
    return kitu +'A'-'a';
}
int main()
{
    char a,b;
    cin>>a>>b;
    for (char kt=a;kt<=b;kt++)
        {
            cout << viethoa(kt) << " ";
        }
    return 0;
}
