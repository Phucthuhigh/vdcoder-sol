// DPRECTA

#include <iostream>
#include <algorithm>

using namespace std;

// Inp
int n, a[10000], b[10000];

long long dp[2][10000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    cin >> n;
    for (int i = 0, x, y; i < n; ++i)
    {
        cin >> a[i] >> b[i];
    }

    // [0][i] la hcn thu i nam ngang
    dp[0][0] = b[0];
    dp[1][0] = a[0];

    for (int i = 1; i < n; ++i)
    {
        dp[0][i] = b[i] + max(dp[0][i - 1] + abs(a[i] - a[i - 1]), dp[1][i - 1] + abs(a[i] - b[i - 1]));
        dp[1][i] = a[i] + max(dp[0][i - 1] + abs(b[i] - a[i - 1]), dp[1][i - 1] + abs(b[i] - b[i - 1]));
    }

    cout << max(dp[0][n - 1], dp[1][n - 1]);
    return 0;
}
    