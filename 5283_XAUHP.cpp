// XAUHP

#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
#include<cmath>
#define ff     first
#define ss     second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2e5 + 8;
string s, t;

bool check() {
    for (int i = 1; i < s.size(); ++i) {
        if (abs(s[i] - s[i - 1]) != abs(t[i] - t[i - 1]))
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int test; cin >> test; while (test--) {
        cin >> s; t = s; reverse(all(t));
        cout << (check() ? "YES\n" : "NO\n");
    }
}
/**  /\_/\
 *  (= ._.)
 *  / >0  \>1
**/
    