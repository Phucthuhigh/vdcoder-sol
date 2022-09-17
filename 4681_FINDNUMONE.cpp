// FINDNUMONE

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
int n, k;
string s("");

string getnp(int a)
{
    if (a == 0) return "0";
    string s("");
    while (a > 0)
    {
        s += char(48 + (a & 1));
        a >>= 1;
    }
    reverse(s.begin(), s.end());
    return s;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1, a; i <= n; ++i)
    {
        cin >> a;
        s += getnp(a);
    }
    n = s.size();
    int l = 0, r = s.find_first_of('0'), res = r;
    if (r == -1) r = res = n;
    while (r < n)
    {
        if (s[r] == '0')
        {
            --k;
            while (r < n && s[r] == '0') ++r;
            while (r < n && s[r] == '1') ++r;
        }

        if (k < 0)
        {
            while (l < n && s[l] == '1') ++l;
            while (l < n && s[l] == '0') ++l;
            ++k;
        }
        res = max(res, r - l);
    }
    cout << res;
    return 0;
}
    