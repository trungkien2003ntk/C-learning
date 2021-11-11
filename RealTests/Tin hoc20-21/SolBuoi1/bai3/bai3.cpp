#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

string st,opst;

string iodate(string s,char io)
{
    string ngayst,thangst,namst,opstr;
    int dayi,monthi,yeari;
    if (io == 'i')
        {
            ngayst = s.substr(0,2);
            thangst = s.substr(3,2);
            namst = s.substr(6,4);
            opstr = ngayst + thangst + namst;
        }
    if (io == 'o')
        {
            ngayst = s.substr(0,2);
            thangst = s.substr(2,2);
            namst = s.substr(4,4);
            opstr = ngayst + "." + thangst + "." + namst;
        }
    return opstr;
}

bool leapyr(int x)
{
    if (x % 4 == 0)
        return true;
    else
        return false;
}

int daymonth(int mnt,int yr)
{
    unordered_set<int> mnt_even = {4,6,9,11};
    unordered_set<int> mnt_odd = {1,3,5,7,8,10,12};
    if (mnt_odd.find(mnt) != mnt_odd.end())
        return 31;
    if(mnt_even.find(mnt) != mnt_even.end())
        return 30;
    else
        {
            if (leapyr(yr))
                return 29;
            else
                return 28;
        }
}

string nextdate(int d,int m, int y)
{
    string newd,newm,newy,stout;
    int numd,numm,numy;
    
    if (d < daymonth(m,y))
        {
            numd = d + 1;
            newd = to_string(numd);
            newm = to_string(m);
            newy = to_string(y);
        }
    else
    {
        if (m == 12)
        {
            newd = newm = "01";
            numy = y + 1;
            newy = to_string(numy);       
        }
        else
        {
            numm = m + 1;
            newm = to_string(numm);
            newd = "01";
            newy = to_string(y);
        }
    }
if (newd.length()==1)
    newd = "0" + newd;
if (newm.length()==1)
    newm = "0" + newm;
while (newy.length()<4)
    newy = "0" + newy;
stout = newd + newm + newy;
return stout;
}

int takedate(string date,char decide)
{
    int rt,tday,tmonth,tyear;
    string sday,smonth,syear;
    sday = date.substr(0,2);
    smonth = date.substr(2,2);
    syear = date.substr(4);
    if (decide == 'd')
        {
            tday = stoi(sday);
            rt = tday;
        }
    if (decide == 'm')
        {
            tmonth = stoi(smonth);
            rt =  tmonth;
        }
    if (decide == 'y')
        {
            tyear = stoi(syear);
            rt = tyear;
        }
    return rt;
}

bool check(string stck)
{
    bool kq = true;
    for (int i=0;i<stck.length()/2;i++)
        if (stck[i] != stck[stck.length()-i-1])
            {
                kq = false;
                break;
            }
    return kq;
}

void solve()
{
    cin >> st;  
    string s;
    s = iodate(st,'i');
    do s = nextdate(takedate(s,'d'),takedate(s,'m'),takedate(s,'y'));
    while  (!(check(s)));
    cout << iodate(s,'o') << endl;
}

int main()
{
    solve();  
    return 0;
}

