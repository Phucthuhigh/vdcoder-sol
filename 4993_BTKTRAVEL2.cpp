// BTKTRAVEL2

#include <iostream>

using namespace std;

// Inp
int n, c[16][16];

// Work
long long res = 1000000000000;
int arr[16];

bool check[16] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };

long long s = 0;
int travel[16], cnt = 0;

void btk()
{
    if (s >= res) return;
    if (cnt == n)
    {
        res = s;
        for (int i = 0; i < n; ++i) arr[i] = travel[i];
    }
    else
    {
        for (long i = 0; i < n; ++i)
        {
            if (check[i])
            {
                s += c[travel[cnt - 1]][i];
                travel[cnt++] = i;
                check[i] = false;

                btk();

                --cnt;
                s -= c[travel[cnt - 1]][travel[cnt]];
                check[i] = true;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) cin >> c[i][j];

    for (int i = 0; i < n; ++i)
    {
        travel[cnt++] = i;
        check[i] = false;

        btk();

        --cnt;
        check[i] = true;
    }

    for (int i = 0; i < n; ++i)
        cout << arr[i] + 1 << ' ';

    return 0;
}
    