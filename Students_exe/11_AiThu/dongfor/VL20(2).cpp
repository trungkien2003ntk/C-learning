#include<iostream>

using namespace std;

int main()
{
    char a,b;
    cin >>a >>b;
    for (char kitu=a;kitu<=b;kitu++)
    {
        cout <<(char)(kitu+'A'-'a') << " ";
    }
    return 0;
}
