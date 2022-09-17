// TRUYENT

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
const int N = 1e5 + 9;
int n, z[N];
char s[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> s;
    for (int i = 1, l, r(0); i < n; ++i) {
        if (r < i) {
            l = r = i;
            while (r < n && s[r] == s[r - l]) ++r;
            z[i] = r - l;
        }
        else {
            if (i + z[i - l] < r) z[i] = z[i - l];
            else {
                l = i;
                while (r < n && s[r] == s[r - l]) ++r;
                z[i] = r - l;
            }
        }
    }

    for (int i = 1; i < n; ++i)
    if (i + z[i] >= n) {
        cout << i;
        return 0;
    }
    cout << n;
}
/**  /\_/\
 *  (= ._.)
 *  / >0  \>1
**/
    