// DPLIS2

#include <iostream>
#include <stack>

using namespace std;

int n, a[200000], f[200001], cnt, then[200001]; // f = pos

int binsearch(int k)
{
	int l = 1, r = cnt, res = 0, mid;
	while (l <= r)
	{
		mid = (l + r) >> 1;

		if (a[f[mid]] == k) return mid - 1;

		if (a[f[mid]] < k)
		{
			res = mid;
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];

	f[0] = -1;
	for (int i = 0; i < n; ++i)
	{
		int pos = binsearch(a[i]);
		if (cnt == pos) f[++cnt] = i;
		else f[pos + 1] = i;

		then[i] = f[pos];
	}

	stack<int> st;
	for (int x = 0, i = f[cnt]; x < cnt; ++x)
	{
		st.push(i + 1);
		i = then[i];
	}

	cout << cnt << '\n';
	while (!st.empty())
	{
		cout << st.top() << ' ';
		st.pop();
	}

	return 0;
}
    