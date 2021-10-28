#include <iostream>
// Thu vien de nhap xuat file <ifstream> <ofstream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string line[5];
    int i,n;
    n=0;
    ifstream f;
    f.open("text.txt");
    // eof() - end of file
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
