

#include <bits/stdc++.h>

using namespace std;
void xuatmang();
void nhap();
void xuat();
int arr[3][3], count_Zero = 0;
bool arr_Bool[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

void nhap()
{
    ifstream f;
    f.open("HVDEP.INP");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            f >> arr[i][j];
            if (arr[i][j] == 0)
                arr_Bool[i][j] = 1;
        }
    f.close();
}

void xuat()
{
    ofstream f;
    f.open("HVDEP.OUT");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            f << arr[i][j] << ' ';
        if (i != 2)
            f << endl;
    }
    f.close();
}

long long sum_Ngang(int arr[3][3], int hang)
{
    return arr[hang][0] + arr[hang][1] + arr[hang][2];
}

long long sum_Doc(int arr[3][3], int cot)
{
    return arr[0][cot] + arr[1][cot] + arr[2][cot];
}

void xuli()
{
    long long sum_All = 0;
    long long sum_Huyen = arr[0][0] + arr[1][1] + arr[2][2];
    long long sum_Sac = arr[0][2] + arr[1][1] + arr[2][0];
    // Khoi tao cac line
    int line_Ngang[3] = {0, 0, 0}, line_Doc[3] = {0, 0, 0}, line_Cheo[2] = {0, 0};
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            if (arr_Bool[i][j] == 1)
            {
                line_Ngang[i] += 1;
                line_Doc[j] += 1;
                if (i == j)
                {
                    if (i == 1)
                    {
                        line_Cheo[0] += 1;
                        line_Cheo[1] += 1;
                    }
                    else
                        line_Cheo[0] += 1;
                }
                else if (i != 1 && j != 1)
                    line_Cheo[1] += 1;
            }
        }
    // Tinh tong dong khong co 0
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            if (line_Ngang[i] == 0)
                sum_All = sum_Ngang(arr, i);
            else if (line_Doc[j] == 0)
                sum_All = sum_Doc(arr, j);
            else if (line_Cheo[0] == 0)
                sum_All = sum_Huyen;
            else if (line_Cheo[1] == 0)
                sum_All = sum_Sac;
        }
    //  Thay the vi tri cac so 0
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr_Bool[i][j] == 1)
            {
                arr[i][j] = sum_All;
                if (line_Ngang[i] != 2)
                {
                    for (int k = 0; k < 3; k++)
                        if (k != j)
                            arr[i][j] -= arr[i][k];
                }
                else if (line_Doc[j] != 2)
                {
                    for (int k = 0; k < 3; k++)
                        if (k != i)
                            arr[i][j] -= arr[k][j];
                }
                else if (line_Cheo[0] != 2)
                {
                    for (int k = 0; k < 3; k++)
                        if (k != i)
                            arr[i][j] -= arr[k][k];
                }
                else if (line_Cheo[1] != 2)
                {
                    for (int k = 0; k < 3; k++)
                        if (k != 2 - k)
                            arr[i][j] -= arr[k][2 - k];
                }
            }
        }
    }
}

int main()
{
    nhap();
    xuli();
    xuat();
    return 0;
}

// 114 line code
