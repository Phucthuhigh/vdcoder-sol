// DPLAGA2

#include <iostream>
using namespace std;
long long f[1005];
int n, mod = (int)1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    f[0] = 1, f[1] = 3;
    for (int i = 2; i <= n; ++i)
        f[i] = (f[i - 2] * 3 + (f[i - 1] - f[i - 2]) * 2) % mod;
    cout << f[n];
    return 0;
}
    