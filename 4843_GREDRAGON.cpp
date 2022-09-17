// GREDRAGON

#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
pair<long, long> a[1000];
int main()
{
	long s, n;
	cin >> s >> n;
	for (long i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;

	sort(a, a + n);

	for (long i = 0; i < n; ++i)
	{
		if (s > a[i].first) s += a[i].second;
		else { cout << "NO"; return 0; }
	}
	cout << "YES";
	return 0;
}
    