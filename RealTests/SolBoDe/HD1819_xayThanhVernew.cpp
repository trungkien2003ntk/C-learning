#include <iostream>
#include <string>
using namespace std;
string st,subst,arr[1000000],save[1000000];
int cs=0;

void xuly();
bool check();

bool check(string x)
{
    bool kq = false;
    for (int i = 0;i<=cs;i++)
        if (save[i]==x)
            kq = true;
    return kq;
}
void xuly()
{
    getline(cin,st);
    for (int i = 0; i<=st.length();i++)
        for (int j=1;j<=st.length()-i;j++)
            {
                subst = st.substr(i,j);
                if (!check(subst))
                    {
                        cs++;
                        save[cs] = subst;
                    }
            }
    cout << cs << endl;
}

int main()
{
    xuly();
    return 0;
}