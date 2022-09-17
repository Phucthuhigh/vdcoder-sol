// DPBATMAN

/// Monarchuwu
// #pragma GCC optimize ("trapv") //interger overflow
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC optimization ("O3")

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
#define cntBit1(x) __builtin_popcount(x)
#define filename "NAME"
//#define cin fi
//#define cout fo
/// IO

using namespace std;
//ifstream fi(filename".INP", ios::in);
//ofstream fo(filename".OUT", ios::out | ios::trunc);

typedef short int sint;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pil> vil;
typedef vector<pli> vli;
typedef vector<pll> vll;

template<typename _type_>
inline void readInt(_type_& num) {
    register char c = cin.get();
    while (c != '-' && ('0' > c || c > '9')) c = cin.get();
    bool neg = false;
    if (c == '-') neg = true, c = cin.get();
    for (num = 0; '0' <= c && c <= '9'; c = cin.get()) num = (num << 1) + (num << 3) + (c - '0');
    if (neg) num = -num;
}

template<typename _type_>
inline void writeInt(_type_ num) {
    if (num < 0) {
        cout.put('-');
        writeInt(-num);
        return;
    }

    if (num > 9) writeInt(num / 10);
    cout.put(num % 10 + '0');
}

const int N = 1006, oo = (int)1e9 + 7, mod[] = { (int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9 + 9277 };
int t, n, m, dp[N];
ll h[N];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    readInt(t);
    while (t-- > 0)
    {
        readInt(n); readInt(m);
        int res = 0;
        for (int i = 1; i <= n; ++i)
        {
            readInt(h[i]);
            dp[i] = 1;
            for (int j = 1; j < i; ++j)
                if (h[j] > h[i]) dp[i] = max(dp[i], dp[j] + 1);
            if (i > m) dp[i] = max(dp[i], dp[m] + 1);
            res = max(res, dp[i]);
        }
        cout << res << '\n';
    }
    return 0;
}
    