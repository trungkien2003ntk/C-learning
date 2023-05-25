#include <bits/stdc++.h>
//#include <windows.h>
//#include <Psapi.h>

using namespace std;
vector<int> val, counter;
vector<set<int>> banDo;
int N, bg[501][501], visited[501][501], amount, cur_space = 0, op_space = 1e9, invaded = 0;
int xve[4] = {-1, 1, 0, 0};
int yve[4] = {0, 0, 1, -1};
vector<bool> tracker;

void nhapfile()
{
    ifstream f("robot2.inp");
    f >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            f >> bg[i][j];
    f.close();
}

void nhapConsole()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> bg[i][j];
}

void xuat()
{
    cout << N << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << bg[i][j] << " ";
        cout << endl;
    }
}

void buildTrace(int x, int y)
{
    banDo[x].insert(y);
    banDo[y].insert(x);
}

void tracking(int x, int y)
{
    counter[amount]++;
     cout << amount << " " << x << " " << y << " " << counter[amount] << endl;
    visited[x][y] = amount;

    for (int i = 0; i < 4; i++){
        if (x + xve[i] <0 || x+ xve[i] >=N || y+yve[i]<0 || y+yve[i]>=N)
            continue;
        else if (!visited[x+xve[i]][y+yve[i]] && bg[x+xve[i]][y+yve[i]] == val[amount])
            tracking(x + xve[i],y+yve[i]);
    }

    // Maping
    if (x - 1 >= 0 && visited[x - 1][y] && amount != visited[x - 1][y])
        buildTrace(amount, visited[x - 1][y]);
    if (x + 1 < N && visited[x + 1][y] && amount != visited[x + 1][y])
        buildTrace(amount, visited[x + 1][y]);
    if (y - 1 >= 0 && visited[x][y - 1] && amount != visited[x][y - 1])
        buildTrace(amount, visited[x][y - 1]);
    if (y + 1 < N && visited[x][y + 1] && amount != visited[x][y + 1])
        buildTrace(amount, visited[x][y + 1]);
}

void xuatcounter()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << visited[i][j] << " ";
        cout << endl;
    }
}

void xuatmap()
{
    for (int i = 0; i < amount; i++)
    {
        cout << "i=" << i << ' ';
        for (auto it = banDo[i].begin(); it != banDo[i].end(); it++)
            cout << *it << ' ';
        cout << endl;
    }
    cout << amount;
}

void xulytho()
{
    // Tracing
    val.push_back(0);
    counter.push_back(0);
    tracker.push_back(false);
    vector<int> tempt;
    set<int> null_set;
    banDo.push_back(null_set);
    amount = 1;
    if (amount < N * N)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (!visited[i][j])
                {
                    val.push_back(bg[i][j]);
                    counter.push_back(0);
                    banDo.push_back(null_set);
                    tracker.push_back(false);
                    tracking(i, j);
                    // xuatcounter();
                    // cout << endl;
                    amount++;
                }
    }
     for (int i = 1; i <= amount; i++)
         cout << val[i] << " " << counter[i] << endl;
}

// void checkSize()
//{
//     // Return current working size
//     PROCESS_MEMORY_COUNTERS memCounter;
//     BOOL result = K32GetProcessMemoryInfo(GetCurrentProcess(), &memCounter, sizeof(memCounter));
//     cout << "WorkingSetSize " << (float)memCounter.WorkingSetSize / 1048576 << " MB" << endl;
// }

void xulycuoi(int x, int minval, int maxval)
{
    cur_space = maxval - minval;
    if (invaded >= round((float)(N * N) / 2) && op_space > cur_space)
        op_space = cur_space;
    else
        for (auto it = banDo[x].begin(); it != banDo[x].end(); it++)
            if (!tracker[*it])
            {
                tracker[*it] = true;
                invaded += counter[x];
                int mi = min(minval, val[*it]), Ma = max(maxval, val[*it]);
                xulycuoi(*it, mi, Ma);
                invaded -= counter[x];
                tracker[*it] = false;
            }
}

int main()
{
    nhapfile();
    //        nhapConsole();
    //    xuat();
    xulytho();
    for (int i = 1; i < amount; i++)
    {
        invaded += counter[i];
        tracker[i] = true;
        xulycuoi(i, val[i], val[i]);
        invaded -= counter[i];
        tracker[i] = false;
    }
    if (N == 1)
        cout << 0;
    else
        cout << op_space;
    return 0;
}