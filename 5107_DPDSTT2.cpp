// DPDSTT2

/// Monarchuwu
//#pragma GCC optimize ("trapv") //interger overflow
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimization ("O3")

#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pp pop_back
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define cntBit1(x) __builtin_popcount(x)
using namespace std;

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
    while (c != '-' && ('0' > c | c > '9')) c = cin.get();
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

const int N = (int)1e6 + 7, oo = (int)1e9 + 7, mod[] = { (int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9 + 9277 };
int n, f[N], pr[N], cnt, maxx[N];

void eratos()
{
    for (int i = 2; i <= 1000000; ++i)
    {
        if (!f[i]) f[i] = pr[++cnt] = i;
        for (int j = 1; j <= cnt && pr[j] <= f[i] && pr[j] * i <= 1000000; ++j)
            f[pr[j] * i] = pr[j];
    }
}

int getmax(int k)
{
    int res = 0, tmp;
    while (k > 1)
    {
        tmp = f[k];
        res = max(res, maxx[tmp]);
        while (f[k] == tmp) k /= tmp;
    }
    return res;
}

void update(int k, int ma)
{
    int tmp;
    while (k > 1)
    {
        tmp = f[k];
        maxx[tmp] = max(maxx[tmp], ma);
        while (f[k] == tmp) k /= tmp;
    }
}

signed main()
{
    eratos();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    readInt(n);
    int res = 0;
    for (int i = 1, a, s; i <= n; ++i)
    {
        readInt(a);
        s = getmax(a);
        res = max(res, s + 1);
        update(a, s + 1);
    }
    cout << res;
    return 0;
}
    