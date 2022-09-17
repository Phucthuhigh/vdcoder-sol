// BTKCATU2

#include <iostream>
#include <utility>

using namespace std;

#define w first
#define v second
#define pll pair<long long, long long>
#define pli pair<long long, int>

int n;
long long m;
pli res = { 0,0 };
pll a[24];

int dem(int k)
{
	int res = 0;
	while (k > 0)
	{
		res += k & 1;
		k >>= 1;
	}
	return res;
}
void output(int k)
{
	int i = 1;
	cout << dem(k) << '\n';
	while (k > 0)
	{
		if (k & 1) cout << i << ' ';
		++i; 
		k >>= 1;
	}
}
void BT(pll sum, int his, int pos)
{
	if (sum.w > m) return;
	if (pos == n)
	{
		if (res.w < sum.v)
			res = { sum.v, his };
		return;
	}

	BT(sum, his << 1, pos + 1);
	BT({ sum.w + a[pos].w, sum.v + a[pos].v }, his << 1 | 1, pos + 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n >> m;
	for (int i = n - 1; i >= 0; --i) cin >> a[i].w >> a[i].v;

	BT({ 0,0 }, 0, 0);

	output(res.v);

	return 0;
}
    