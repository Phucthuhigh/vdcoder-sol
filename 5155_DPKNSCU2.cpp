// DPKNSCU2

#include <iostream>
#include <vector>
using namespace std;
const int W = 502, N = 102;
int w, n, c[N], v[N], dp[502];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    while (cin >> w >> n)
    {
        if (!w && !n) break;
        for (int i = 1; i <= n; ++i) cin >> c[i] >> v[i];

        fill(dp + 1, dp + W, 0);
        dp[c[1]] = v[1];
        for (int i = 2; i <= n; ++i)
            for (int j = w; j >= c[i]; --j)
                dp[j] = max(dp[j], dp[j - c[i]] + v[i]);

        int vma = 0, wma = 0;
        for (int i = 1; i <= w; ++i)
            if (dp[i] > vma)
            {
                vma = dp[i];
                wma = i;
            }

        cout << wma << ' ' << vma << '\n';
    }
    return 0;
}
    