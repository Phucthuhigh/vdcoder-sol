// BTKTRAU4

/// Monarchuwu

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
/// IO

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
/// Data Structure

#include <algorithm>
#include <cstdlib>
#include <numeric>
/// Algorithm

#include <climits>
#include <cstring>
#include <cmath>
/// C library

#include <ctime>
/// Time

#define fi first
#define se second
#define mp make_pair
#define pp pop_back
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
/// IO

using namespace std;

typedef short int sint;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;

const int N = 40, oo = (int)1e9 + 7, mod[] = { (int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9 + 9277 };
int n, a[N], cntb = 1, cntc = 1;
ll s, b[1 << 20], c[1 << 20];

void meet_in_the_middle()
{
    int n1 = n >> 1;
    for (int i = 1; i <= n1; ++i)
    {
        for (int j = 1; j <= cntb; ++j)
            b[j + cntb] = b[j] + a[i];
        cntb <<= 1;
    }

    for (int i = n1 + 1; i <= n; ++i)
    {
        for (int j = 1; j <= cntc; ++j)
            c[j + cntc] = c[j] + a[i];
        cntc <<= 1;
    }
}

ll calc()
{
    sort(c + 1, c + cntc + 1, greater<ll>());
    ll res = s, sum = s >> 1;
    for (int i = 1, j; i <= cntb; ++i)
    {
        j = lower_bound(c + 1, c + cntc + 1, sum - b[i], greater<ll>()) - c;
        res = min(res, abs(s - (b[i] + c[j]) * 2));
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], s += a[i];
    meet_in_the_middle();
    cout << calc();
    return 0;
}
    