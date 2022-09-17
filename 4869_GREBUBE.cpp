// GREBUBE

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
vector<int> a;
int binsearch(int l, int r, int k)
{
	int mid, res = -1;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (a[mid] == k) return mid;
		if (a[mid] < k)
		{
			res = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return res;
}
/*
void xuat()
{
	for (int i = 0; i < a.size(); ++i)cout << a[i] << ' ';
	cout << '\n';
}
*/
int main()
{
	cin >> n >> k;
	a.resize(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	
	sort(a.begin(), a.end());
	
	int i = 0;
	while (i > -1)
	{
		int vt = binsearch(0, n - i - 1, a[n - i - 1] - k), tmp;
		if (vt == -1) break;
		while (vt != -1)
		{
			tmp = a[vt];
			a.erase(a.begin() + vt);
			++i;
//			xuat();
			vt = binsearch(0, vt - 1, tmp - k);
		}
		++i;
	}
	
	long long res = 0;
	for (int i = 0, siz = a.size(); i < siz; ++i) res += a[i];
	cout << res;
	return 0;
}
    