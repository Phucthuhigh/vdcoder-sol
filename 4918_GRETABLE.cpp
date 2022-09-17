// GRETABLE

#include <iostream>
#include <algorithm>
#define sum first
#define cnt second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = (int)1e5 + 9, D = (int)2e4 + 1;
int n, suf[N];
pii bit[D];
struct data {
	int l, d;
	bool operator < (const data& other) const {
		return l < other.l;
	}
} a[N];

void operator += (pii& x, const pii& y) {
	x.sum += y.sum;
	x.cnt += y.cnt;
}

pii query(int p) {
	pii ans(0, 0);
	for (; p > 0; p -= p & (-p)) ans += bit[p];
	return ans;
}

void update(int p, int val) {
	for (; p < D; p += p & (-p)) bit[p] += pii(val, 1);
}

int bsearch(int num) { // luong chan it nhat can delete is num
	int mid, l = 0, r = D - 1;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (query(mid).cnt >= num) r = mid - 1;
		else l = mid + 1;
	}
	return r + 1; // energy of cha^n thu?' num (sorted 1->i)
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i].l;
	for (int i = 1; i <= n; ++i) cin >> a[i].d;
	sort(a + 1, a + n + 1);

	for (int i = n; i > 0; --i) suf[i] = suf[i + 1] + a[i].d;

	int res = 2e9;
	for (int i = 1, j = 0; i <= n; ++i) {
		if (i == n || a[i].l < a[i + 1].l) {
			int p = bsearch(j - (i - j) + 1); // j is chan khong thoa, i-j is count a[x].l = a[i].l => j-(i-j)+1 la luong chan it nhat can delete
			pii cost = query(p);
			if (p < D) cost.sum -= p * (cost.cnt - (j - (i - j) + 1)); // luong chan enery p khong can delete
			res = min(res, cost.sum + suf[i + 1]); // suf[i + 1] is cost when delete chan^ co' l[x] > a[i].l
			while (j < i) {
				update(a[j + 1].d, a[j + 1].d);
				++j;
			}
		}
	}
	cout << res;
	return 0;
}
    