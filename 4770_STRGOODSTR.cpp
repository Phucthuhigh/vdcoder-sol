// STRGOODSTR

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 1e5 + 1000;
int n, m;
char s[N], p[N];

int numBlock[256], num[256];
bool check() {
    for (int i = 'a'; i <= 'z'; ++i) if (num[i] > numBlock[i]) return false;
    return true;    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> s + 1 >> p + 1; n = strlen(s + 1), m = strlen(p + 1);
    if (n < m) { cout << 0; return 0; }

    int res = 0;
    for (int i = 1; i <= m; ++i) ++numBlock[p[i]];
    for (int i = 1; i <= n; ++i) {
        ++num[s[i]]; // ignore '?'
        if (i < m) continue;

        --num[s[i - m]]; // ignore '?'
        if (check()) ++res;
    }
    cout << res;
}
    