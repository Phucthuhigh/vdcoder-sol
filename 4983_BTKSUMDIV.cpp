// BTKSUMDIV

#include <iostream>

using namespace std;

int n;
long long k, a[22];
int res = 0;

void build(long long s, int pos, int len)
{
	if (s % k == 0) res = max(res, len);
	if (pos == n) return;
	build(s, pos + 1, len);
	build(s + a[pos], pos + 1, len + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> a[i];
	build(0, 0, 0);
	cout << res;
	return 0;
}
    