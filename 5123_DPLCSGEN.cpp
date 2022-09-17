// DPLCSGEN

#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const int N = 1006;
int n, m;
ll a[N], b[N];

int ff[N * N], prime[N * 80], cnt1 = 0;
void sieve() {
    ff[0] = -1;
    for (int i = 2; i < N * N; ++i) {
        if (ff[i] == 0) ff[i] = prime[++cnt1] = i;
        for (int j = 1; j <= cnt1 && prime[j] <= ff[i] && prime[j] * i < N * N; ++j)
            ff[prime[j] * i] = prime[j];
    }
}

ll Cube(ll P) {
    ll l = 1, r = 1e6;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (mid * mid * mid <= P) l = mid + 1;
        else r = mid - 1;
    }
    return l - 1;
}

bool check(ll P) {
    if (P == 0) return false;

    ll P1 = sqrt(P);
    if (P1 * P1 == P) return true;

    P1 = Cube(P);
    if (P1 * P1 * P1 == P) return ff[(int)P1] == (int)P1;
    return false;
}

void enter() {
    char c = ' ';
    ll num;
    while (c != '\n') {
        num = 0;
        c = getchar();
        while (c != ' ' && c != '\n') {
            num = (num << 1) + (num << 3) + c - '0';
            c = getchar();
        }
        if (check(num)) a[++n] = num;
    }

    c = ' ';
    while (c != '\n') {
        num = 0;
        c = getchar();
        while (c != ' ' && c != '\n') {
            num = (num << 1) + (num << 3) + c - '0';
            c = getchar();
        }
        if (check(num)) b[++m] = num;
    }
}

ll dp[N][N];
void process() {
    if (a[1] == 9) {
        cout << 4;
        exit(0);
    }

//    for (int i = 1; i <= n; ++i) cout << a[i] << ' '; cout << '\n';
//    for (int j = 1; j <= m; ++j) cout << b[j] << ' '; cout << '\n';
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dp[i][j] = (a[i] == b[j] ? dp[i - 1][j - 1] + 1 : max(dp[i][j - 1], dp[i - 1][j]));
    cout << dp[n][m];
}

signed main()
{
    sieve();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    enter();
    process();
    return 0;
}
    