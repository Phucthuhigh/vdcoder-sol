// DPRCCHO

#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int n, m, k;
long long s[6001], f[6001][6001], maxx[6001]; // f[i,j] là lấy đoạn thứ i tại vị trí j (j = ri)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    k = min(k, (n + m - 1) / m);
    for (int i = 1, p; i <= n; ++i)
    {
        cin >> p;
        s[i] = s[i - 1] + p;
    }

    long long res = 0;
    for (int i = 1; i <= k; ++i)
        for (int j = m; j <= n; ++j)
        {
            if (j > m) maxx[j - m] = max(maxx[j - m - 1], f[i - 1][j - m]);
            f[i][j] = (s[j] - s[j - m]) + maxx[j - m];
            res = max(res, f[i][j]);
        }

    cout << res;
    return 0;
}
    