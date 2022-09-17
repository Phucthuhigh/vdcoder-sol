// STRACTG

#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = (int)1e5 + 9, mod = (int)1e9 + 7;

int n;
string s;

int dist(char a, char b) {
    if (a > b) swap(a, b); // a <= b
    return min(b - a, a - b + 26);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> s;
    int ans = 100;
    for (int i = 3; i < n; ++i) {
        ans = min(ans, dist(s[i - 3], 'A') + dist(s[i - 2], 'C') + dist(s[i - 1], 'T') + dist(s[i], 'G'));
    }
    cout << ans;
    return 0;
}
    