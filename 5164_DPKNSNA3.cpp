// DPKNSNA3

/// Monarchuwu
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimization ("O3")

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
/// IO

#include <unordered_map>
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

//#define cin fi
//#define cout fo
/// IO


#define fi first
#define se second
#define mp make_pair
#define pp pop_back
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define filename "NAME"

using namespace std;

typedef short int sint;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;

const int N = 202, oo = (int)1e9 + 7, mod[] = {(int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9 + 9277 };
int n, m1, m2, dp[N][N][N];

signed main()
{
	ios_base::sync_with_stdio(false);
	int res = 0;
	cin >> m1 >> m2 >> n;
	for (int i = 1, v, w; i <= n; ++i)
    {
        cin >> v >> w;
        for (int j = 0; j <= m1; ++j)
            for (int k = 0; k <= m2; ++k)
            {
                dp[i][j][k] = dp[i - 1][j][k];
                if (j >= w) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - w][k] + v);
                if (k >= w) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - w] + v);
                res = max(res, dp[i][j][k]);
            }
    }
    cout << res;
	return 0;
}
    