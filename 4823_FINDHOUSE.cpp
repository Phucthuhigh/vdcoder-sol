// FINDHOUSE

#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int N = (int)2e5 + 5, oo = 1e9 + 7;
int n;
struct house {
	ll h, c;
	bool operator < (const house& other) const {
		return (h < other.h);
	}
} a[N];

void input()
{
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i].h;
	for (int i = 1; i <= n; ++i) cin >> a[i].c;
	sort(a + 1, a + n + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	input();
	ll sum = 0, c1 = 0, c2 = 0;
	for (int i = n; i > 1; --i)
		sum += a[i].c * (a[i].h - a[1].h), c2 += a[i].c;

	ll res = sum;
	for (int i = 2; i <= n; ++i)
	{
		c1 += a[i - 1].c;
		sum += c1 * (a[i].h - a[i - 1].h) - c2 * (a[i].h - a[i - 1].h);
		res = min(res, sum);
		c2 -= a[i].c;
	}
	cout << res;
	return 0;
}
    