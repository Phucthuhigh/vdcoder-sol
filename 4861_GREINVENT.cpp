// GREINVENT

#include <iostream>
#include <queue>

using namespace std;

int n, a[100005];
bool c[100005];
queue<int> q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		if (a[i] <= n && !c[a[i]]) c[a[i]] = true;
		else q.push(i);
	}

	for (int i = 1, x; i <= n; ++i)
	{
		if (!c[i])
		{
			x = q.front(); q.pop();
			a[x] = i;
		}
	}

	for (int i = 1; i <= n; ++i) cout << a[i] << ' ';

	return 0;
}
    