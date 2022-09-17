// STR2NSWAP

#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 56;
int n, cnt;
string s, t;
pii ans[N << 1];
bool process() {
    for (int i = 0, j; i < n; ++i)
        if (s[i] != t[i]) {
            j = i + 1;
            while (j < n) {
                if (s[j] != t[j]) {
                    if (s[i] == s[j]) { // s[j] <-> t[i]
                        swap(s[j], t[i]);
                        ans[cnt++] = pii(j + 1, i + 1);
                        break;
                    }

                    if (s[i] == t[j]) { // ab ca -> aa cb -> ac ab
                        swap(s[j], t[j]);
                        swap(t[i], s[j]);
                        ans[cnt++] = pii(j + 1, j + 1);
                        ans[cnt++] = pii(j + 1, i + 1);
                        break;
                    }
                }
                ++j;
            }
            if (j == n) return false;
        }
    return true; // cnt <= 2 * n
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int test; cin >> test;
    while (test-- > 0) {
        cin >> n >> s >> t;
        cnt = 0;
        if (process()) {
            cout << "Yes\n" << cnt << '\n';
            for (int i = 0; i < cnt; ++i) cout << ans[i].first << ' ' << ans[i].second << '\n';
        }
        else cout << "No\n";
    }
}
    