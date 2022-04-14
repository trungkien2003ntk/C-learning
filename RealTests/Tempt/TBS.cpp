#include <iostream>
#include <fstream>
using namespace std;
int dem=0,check=0;
    float a[4];
void xuat()
{
        ofstream f1;
        f1.open("TBS.OUT");
        if(check==1)
        {
            f1<<0;
            cout<<0;
        }
        else
            if(dem%2==0)
            {
                f1<<1;
                cout<<1;
            }
            else
            {
                f1<<-1;
                cout<<-1;
            }
        f1.close();
}

int main()
{
    
    ifstream f;
    f.open("TBS.INP");
    for(int x=1;x<=4;x++)
    {
        f>>a[x];
        if(a[x]==0.0)
        {
            check=1;
            break;
        }
        if(a[x]<0)
            dem++;
    }
    f.close();
    xuat();
    
}