#include <iostream>
#include <fstream>

using namespace std;

int N, half;
int a[501][501];
int trackX[4] = {0,0,1,-1},
    trackY[4] = {1,-1,0,0};

void nhapFile()
{
    ifstream f("robot2.inp");
    f >> N;
    half = N / 2;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            f >> a[i][j];
    f.close();
}

void nhapConsole()
{
    cin >> N;
    half = N / 2;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> a[i][j];
}



int main()
{
    nhapFile();
    // nhapConsole();
 
    
}