#include <iostream>

using namespace std;

int n,d,arr[1000000],gtln=0;

void nhap();
int check(int t);


void nhap()
{
    cin >> n >> d;
    for (int i = 1;i<=n;i++)
        cin >> arr[i];

    // cout << n << "; " << d << endl;
    // for (int i = 1;i<=n;i++)
    //     cout << arr[i] << " ";
}

int check(int t,int k)
{
    int kq,cs;
    kq =-1;
    cs = k;
    while (cs<=n)
        {
            if (arr[cs] == t)
            {
                kq = cs;
                break;
            }
            cs++;
        }
    return kq;
}

void xuly()
{
    int steps,run,counter,pos;
    run = 1;
    while (run<=n)
    {
        steps = run;
        pos = run+1;
        counter = 1;
        while (check(arr[steps]+d,pos)>0)
            {
                counter++;
                steps = check(arr[steps]+d,pos);
                pos = steps+1;
                // cout << counter << endl;
            }
        if (counter>gtln)
            gtln = counter;
        counter =0;
        run++;
    }
}

void xuat()
{
    cout << gtln;
}

int main()
{
    nhap();
    xuly();
    xuat();
}
