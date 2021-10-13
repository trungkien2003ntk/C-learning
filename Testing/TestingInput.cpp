#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const   int Size = 40;
        int arr[Size];

void outFile()
{
    fstream myFile;
    int arr[16];
    for (int i=0; i<5;i++)
    {
        arr[i]=i+1;
    }
    myFile.open("Output.txt",ios::out); //write
    if (myFile.is_open()){
        for (int i=0; i<5;i++)
        {
            myFile << arr[i]<<endl;
        }
        myFile.close();
    }
    myFile.open("Output.txt",ios::app); //append
    if (myFile.is_open()){
        myFile << "Second time open the file"<<endl;
        for (int i=0; i<5;i++)
        {
            myFile << arr[i]<<endl;
        }
        myFile.close();
    }

}

void inFile()
{
    string IpFileName= "Input.txt";
    fstream IpFile;
    IpFile.open(IpFileName,ios::in);
}

int main(){
    
 
    //system("pause");
    return 0;
}