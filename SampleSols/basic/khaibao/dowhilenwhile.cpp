#include <iostream>

using namespace std;

int main()
{
    int t = 3;
    int i = 4;
    while (i<=t)
    {
        i++;
        cout << "Gia tri i luc nay la: " << i << endl;
    }

    i = 4;
    do
    {
        i++;
        cout << "Gia tri i luc nay la: " << i << endl;
    }
    while (i<=t);

    return 0;
}
