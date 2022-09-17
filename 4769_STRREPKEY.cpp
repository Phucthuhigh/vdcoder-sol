// STRREPKEY

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

using namespace std;
int n;
char c[256];
string s, t;

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> s >> t;
    int d = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == t[i])
        {
            if (c[s[i]] == 0) c[s[i]] = t[i];
        }
        else
        {
            if (c[s[i]] == 0) c[s[i]] = t[i], ++d;
            if (c[t[i]] == 0) c[t[i]] = s[i], ++d;
        }
        if (c[s[i]] != t[i]) d = 600;
        if (c[t[i]] != s[i]) d = 600;
    }
    if (d >= 600) cout << -1;
    else
    {
        cout << d / 2 << '\n';
        for (int i = 'a'; i <= 'z'; ++i)
        {

            if (c[i] > i) cout << c[i] << ' ' << (char)i << '\n';
        }
    }
    return 0;
}
    