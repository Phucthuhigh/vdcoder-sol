// GREKNIGHT

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct kni {
	int p, c, pos;
} a[100005];

int n, k;
long long ans[100005];

void processing()
{
	vector<int> v;
	long long sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sort(v.begin(), v.end(), greater<int>());
		while (v.size() > k)
		{
			sum -= v.back();
			v.pop_back();
		}

		ans[a[i].pos] = sum + a[i].c;
		
		v.push_back(a[i].c);
		sum += a[i].c;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i].p;
		a[i].pos = i;
	}
	for (int i = 0; i < n; ++i) cin >> a[i].c;

	sort(a, a + n, [](const kni& x, const kni& y) {
		return (x.p < y.p);
	});

	processing();

	for (int i = 0; i < n; ++i)
		cout << ans[i] << ' ';

	return 0;
}
    