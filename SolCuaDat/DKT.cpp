#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    long long N;
    ifstream f;
    f.open("DKT.INP");
    f>>N;
    f.close();
    ofstream f1;
    f1.open("DKT.OUT");
    f1<<(char)(((N*(1+N)/2)%26)+'A');
    f1.close();
}