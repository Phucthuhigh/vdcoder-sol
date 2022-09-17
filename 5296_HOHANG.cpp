// HOHANG

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
int n;
string s, t;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int test; cin >> test; while (test--) {
        cin >> n >> s >> t;
        sort(all(s));
        sort(all(t));
        cout << (s == t) << '\n';
    }
}
/**  /\_/\
 *  (= ._.)
 *  / >0  \>1
**/
    