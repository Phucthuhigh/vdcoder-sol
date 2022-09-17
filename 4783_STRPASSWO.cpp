// STRPASSWO

#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
int n, cnt[3];
string s;

int type(char c) {
    if ('a' <= c && c <= 'z') return 0;
    if ('A' <= c && c <= 'Z') return 1;
    return 2; // 0..9
}

ll process() {
    if (n < 6) return 0;
    long long ans = 0;
    int i = 0, j = 1;
    while (j + 5 <= n) {
        while (j + 5 > i || (i < n && (!cnt[0] || !cnt[1] || !cnt[2]))) ++cnt[type(s[++i])];
        if (!cnt[0] || !cnt[1] || !cnt[2]) break;
        ans += n - i + 1;
        --cnt[type(s[j++])];
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> s; n = s.size(); s = " " + s;
    cout << process();
    return 0;
}
    