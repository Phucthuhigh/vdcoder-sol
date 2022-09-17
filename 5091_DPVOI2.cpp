// DPVOI2

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

const int N = 100005, oo = 1000000007;
int n = 1, b[N], bpos[N], dp[N], pre[N], cnt;
struct ele {
	int w, iq, id;
} voi[N];

// a = voi.iq

void input()
{
	while (cin >> voi[n].w)
	{
		if (voi[n].w == 0) break;
		cin >> voi[n].iq;
		voi[n].iq = oo - voi[n].iq;
		voi[n++].id = n;
	}

	sort(voi, voi + n, [](const ele& x, const ele& y)
		{
			return (x.w < y.w || (x.w == y.w && x.iq < y.iq));
		});
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	input();

	for (int i = 1; i < N; ++i) b[i] = oo;
	for (int i = 1; i < n; ++i)
	{
		int pos = upper_bound(b + 1, b + N, voi[i].iq) - b - 1; // a[i] >= b[pos]
		pre[i] = bpos[pos];
		b[pos + 1] = voi[i].iq, bpos[pos + 1] = i;
		if (pos == cnt) ++cnt;
	}

	cout << cnt << '\n';
	stack<int> st;
	for (int i = cnt, tmp = bpos[cnt]; i > 0; --i)
	{
		st.push(voi[tmp].id);
		tmp = pre[tmp];
	}

	while (!st.empty())
	{
		cout << st.top() - 1 << ' ';
		st.pop();
	}


	return 0;
}
    