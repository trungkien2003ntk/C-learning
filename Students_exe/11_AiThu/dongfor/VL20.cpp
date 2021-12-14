#include<iostream>

using namespace std;

char viethoa(char kt)
{
    return kt+'A'-'a';
}

int main()
{
    char a,b;
    cin >>a >>b;
    for (char kitu=a;kitu<=b;kitu++)
    {
        cout <<viethoa(kitu) << " ";
    }
    return 0;
}
