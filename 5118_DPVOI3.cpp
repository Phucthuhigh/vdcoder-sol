// DPVOI3

#include <iostream>
#include <algorithm>

using namespace std;

const int N = (int)1e5 + 9;
int n, a[N], b[N], cnt;
struct ele {
	int w, iq;
} voi[N];

void input()
{
	while (cin >> voi[++n].w)
	{
		if (voi[n].w == 0) break;
		cin >> voi[n].iq;
	}

	sort(voi + 1, voi + n + 1, [](const ele& x, const ele& y) {
			return (x.iq > y.iq || (x.iq == y.iq && x.w > y.w));
		});

	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (voi[i].w != voi[i - 1].w || voi[i].iq != voi[i - 1].iq)
			a[++cnt] = voi[i].w;
	}
	n = cnt;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	input();
	for (int i = 1, pos; i <= n; ++i) {
		pos = lower_bound(b, b + cnt, a[i]) - b;
		b[pos] = a[i];
		cnt += (cnt == pos);
	}
	cout << cnt << '\n';
	return 0;
}
    