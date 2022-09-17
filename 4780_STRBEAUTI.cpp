// STRBEAUTI

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, k;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> s; s = " " + s;
    string res(n + 1, ' ');
    res[0] = '0'; for (int i = 1; i <= k; ++i) res[i] = s[i];

    int l = 1;
    for (int i = k + 1, j = 1; i <= n; ++i, ++j) {
        if (j > k) j -= k;

        if (res[j] > s[i]) break;
        if (res[j] < s[i]) {
            int x = res[k] - '0' + 1;
            res[k] = char(x % 10 + '0'); x /= 10;
            for (l = k; x > 0; x = x / 10 + res[--l] - '0') 
                res[l] = char(x % 10 + '0');
            break;
        }
    }

    l = min(l, 1);
    cout << n - l + 1 << '\n';
    for (int i = l + k; i <= n; ++i) res[i] = res[i - k];

    if (res[0] > '0') cout << res[0];
    for (int i = 1; i <= n; ++i) cout << res[i];
    return 0;
}
    