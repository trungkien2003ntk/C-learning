#include <bits/stdc++.h>

using namespace std;
string s;
stack<string> datSav, revDat;
vector<string> inputDat;
vector<bool> checker;

void nhapTempt(string st)
{
    s = st;
}

// Cat iterators va iterands ra luu vao mot vector
void split()
{
    int i = 0;
    while (i < s.length())
    {
        int j = 0;
        if (!isdigit(s[i]))
            j = 1;
        else
            while (isdigit(s[i + j]))
                j++;
        string tempt = s.substr(i, j);
        inputDat.push_back(tempt);
        // Tra checker de xac dinh dau la iterator (Toan tu) hoac iterand (hang tu)
        if (j == 1 && !isdigit(tempt[0]))
            checker.push_back(0);
        else
            checker.push_back(1);
        i += j;
    }
}

int prec(string x)
{
    if (x[0] == '^')
        return 3;
    if (x[0] == '*' || x[0] == ':')
        return 2;
    if (x[0] == '+' || x[0] == '-')
        return 1;
    else
        return -1;
}

// Tien hanh xu ly tren tung ky tu cua input string sau do tra ve vi tri can xu ly tiep theo
void xulyInfixToPostfix()
{
    stack<string> datTempt;
    for (int i = 0; i < inputDat.size(); i++)
    {
        if (isdigit(inputDat[i][0]))
            datSav.push(inputDat[i]);
        else if (inputDat[i] == "(")
            datTempt.push("(");

        else if (inputDat[i] == ")")
        {
            while (datTempt.top() != "(")
            {
                datSav.push(datTempt.top());
                datTempt.pop();
            }
            datTempt.pop();
        }
        // Trong truong hop dang xu ly mot toan tu
        else
        {
            while (!datTempt.empty() && prec(inputDat[i]) <= prec(datTempt.top()))
            {
                datSav.push(datTempt.top());
                datTempt.pop();
            }
            datTempt.push(inputDat[i]);
        }
    }
    // Pop toan bo remaining elements trong stack
    while (!datTempt.empty())
    {
        datSav.push(datTempt.top());
        datTempt.pop();
    }

    //    // Xuat thu nghiem
    //    while (!datSav.empty()){
    //        cout << datSav.top() << endl;
    //        datSav.pop();
    //    }
}

// Ham tinh phep tinh hai hang tu x va y voi toan tu t
string calc(string x, string y, string t)
{
    long long first = stoll(x);
    long long last = stoll(y);
    long long llResult;
    string kq;
    if (t == "^")
        llResult = pow(first, last);
    if (t == ":")
        llResult = first / last;
    if (t == "*")
        llResult = first * last;
    if (t == "+")
        llResult = first + last;
    if (t == "-")
        llResult = first - last;
    kq = to_string(llResult);
    return kq;
}

// Reverse stack de tien hanh tinh toan ket qua dua tren postfix
void reverseDataSaved()
{
    while (!datSav.empty())
    {
        revDat.push(datSav.top());
        datSav.pop();
    }
}


void xulyCuoi()
{
    stack<string> datTempt;
    string tempt, iter1, iter2,result;
    while (revDat.size() > 0)
    {
        tempt = revDat.top();
        revDat.pop();
        if (isdigit(tempt[0]))
            datTempt.push(tempt);
        else
        {
            iter2 = datTempt.top();
            datTempt.pop();
            iter1 = datTempt.top();
            datTempt.pop();
            datTempt.push(calc(iter1, iter2, tempt));
        }
    }
    result = datTempt.top();
    cout << result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    nhapTempt("2^5+(3-(3*2+1))-(8*(8+3*2))");
    split();
    xulyInfixToPostfix();
    reverseDataSaved();
    xulyCuoi();
    return 0;
}