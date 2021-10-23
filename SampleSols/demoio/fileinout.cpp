#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string line[5];
    int i,n;
    n=0;
    ifstream f("D:/HSG/Code/SampleSols/demoio/text.txt");
    while (!f.eof())
    {
        getline(f,line[n]);
        n++;
    }
    f.close();
    for (i=0;i<5;i++)
        cout<<"array "<<i<<" contain: "<<line[i]<<endl;
    return 0;
}
