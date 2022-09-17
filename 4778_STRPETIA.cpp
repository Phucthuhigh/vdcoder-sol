// STRPETIA

#pragma GCC optimize ("Ofast")
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int N = 1006;
int n, n2;
string x, s, s2, s3;
bool g[256]; // good

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> x >> s; n = s.size();
    for (char c : x) g[c] = true;
    int t; cin >> t;
    while (t-- > 0) {
        cin >> s2; n2 = s2.size();
        if (n - n2 > 1) cout << "NO\n";
        else {
            bool f = true;
            s3.clear();
            for (int i = 0; i < n; ++i) {
                if (s[i] == '*') {
                    for (int j = 1; j <= n2 - n + 1; ++j) s3.push_back('*');
                }
                else s3 += s[i];
            }
            for (int i = 0; i < n2; ++i) {
                if (s3[i] == '?' && !g[s2[i]]) f = false;
                if (s3[i] == '*' && g[s2[i]]) f = false;
                if (s3[i] != '?' && s3[i] != '*' && s2[i] != s3[i]) f = false;
                if (!f) break;
            }
            cout << (f ? "YES\n" : "NO\n");
        }
    }
    return 0;
}
    