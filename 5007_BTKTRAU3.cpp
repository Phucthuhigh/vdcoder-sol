// BTKTRAU3

#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <fstream>
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;

const int N = 50, oo = (int)1e6 + 9;
int n, a[N];
ll s;
unordered_map<ll, pli> b, c;

void dequy1(ll sum, int i, int n, int bit)
{
	if (sum > s) return;
	if (i > n)
	{
		++b[sum].ff;
		if (b[sum].ff == 1) b[sum].ss = bit;
		else b[sum].ss = min(bit, b[sum].ss);
	}
	else
	{
		dequy1(sum, i + 1, n, bit);
		dequy1(sum + a[i], i + 1, n, bit + 1);
	}
}

void dequy2(ll sum, int i, int n, int bit)
{
	if (sum > s) return;
	if (i > n)
	{
		++c[sum].ff;
		if (c[sum].ff == 1) c[sum].ss = bit;
		else c[sum].ss = min(bit, c[sum].ss);
	}
	else
	{
		dequy2(sum, i + 1, n, bit);
		dequy2(sum + a[i], i + 1, n, bit + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> s;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	dequy1(0, 1, n >> 1, 0);
	dequy2(0, (n >> 1) + 1, n, 0);

	ll res = 0;
	int bit = n + 1;
	for (auto x : b)
	{
		if (c.count(s - x.ff))
		{
			pli y = c[s - x.ff];
			res += x.ss.ff * y.ff;
			bit = min(bit, x.ss.ss + y.ss);
			if (bit == 0)
			{
				int k = 0;
			}
		}
	}

	if (bit == n + 1) cout << "KHONG CHON DUOC";
	else cout << res << ' ' << bit;
	return 0;
}
    