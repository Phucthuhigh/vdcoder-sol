// BTKABC

#include <iostream>
#include <algorithm>
#include <cstring>
#define fname "BTKABC"

using namespace std;

int n, minC = 106;
char x[106], best[106];
int t[106];

bool same(int i, int len) {
    int j = i - len;
    for (int k = 0; k < len; ++k)
        if (x[i - k] != x[j - k]) return false;
    return true;
}

bool check(int i) {
    for (int len = 1; len * 2 <= i; ++len)
        if (same(i, len)) return false;
    return true;
}

void update() {
    minC = t[n];
    for (int i = 1; i <= n; ++i) best[i] = x[i];
}

void Try(int i) {
    for (int j = 'A'; j <= 'C'; ++j) {
        x[i] = char(j);
        if (check(i)) {
            t[i] = t[i - 1] + (j == 'C');
            if (t[i] + (n - i) / 4 < minC) {
                if (i == n) update();
                else Try(i + 1);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    Try(1);
    for (int i = 1; i <= n; ++i) cout << best[i];
    return 0;
}
    