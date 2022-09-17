// BTKTRAU2

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

#define ff first
#define ss second
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

const int N = 35, oo = (int)1e9 + 7, mod[] = { (int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9 + 9277 };
int n, a[N], cntb = 1, cntc = 1, cnt, ans[N];
ll s;
pll b[1 << 20], c[1 << 20];

void meet_in_the_middle()
{
    int n1 = n >> 1;
    for (int i = 1; i <= n1; ++i)
    {
        for (int j = 1; j <= cntb; ++j)
        {
            b[j + cntb].ff = b[j].ff + a[i];
            b[j + cntb].ss = b[j].ss + (1LL << i);
        }
        cntb <<= 1;
    }

    for (int i = n1 + 1; i <= n; ++i)
    {
        for (int j = 1; j <= cntc; ++j)
        {
            c[j + cntc].ff = c[j].ff + a[i];
            c[j + cntc].ss = c[j].ss + (1LL << i);
        }
        cntc <<= 1;
    }
}

bool cmp(const pll& x, const ll& y) {
    return (x.ff < y);
}

bool check()
{
    sort(c + 1, c + cntc + 1);
    for (int i = 1; i <= cntb; ++i)
    {
        int j = lower_bound(c + 1, c + cntc + 1, s - b[i].ff, cmp) - c;

        if (b[i].ff + c[j].ff == s)
        {
            ll num1 = b[i].ss, num2 = c[j].ss;
            for (int i = 0; num1 > 0; ++i)
            {
                if (num1 & 1) ans[++cnt] = i;
                num1 >>= 1;
            }

            for (int i = 0; num2 > 0; ++i)
            {
                if (num2 & 1) ans[++cnt] = i;
                num2 >>= 1;
            }

            return true;
        }
    }
    return false;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    meet_in_the_middle();
    if (check())
    {
        cout << "YES\n" << cnt << '\n';
        for (int i = 1; i <= cnt; ++i) cout << ans[i] << ' ';
    }
    else cout << "NO";

    return 0;
}
    