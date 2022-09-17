// DPKNSPR

#include <iostream>
#include <vector>
using namespace std;
const int N = 1122, K = 16;
int n, k, dp[K][N], cnt, pr[N];
bool era[N];

void eratos()
{
    era[0] = era[1] = true;
    for (int i = 2; i <= N; ++i)
        if (!era[i])
        {
            pr[++cnt] = i;
            for (int j = i * i; j < N; j += i) era[j] = true;
        }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    eratos();
    dp[0][0] = 1;
    for (int l = 1; pr[l] < N; ++l)
    {
        for (int j = N - 1; j >= pr[l]; --j)
        {
            for (int i = K - 1; i > 0; --i)
                dp[i][j] += dp[i - 1][j - pr[l]];
        }
    }

    while (cin >> n >> k)
    {
        if (!n && !k) break;
        cout << dp[k][n] << '\n';
    }
    return 0;
}
    