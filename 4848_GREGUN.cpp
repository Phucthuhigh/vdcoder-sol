// GREGUN

#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
pair<long, long> a[50000];

int main()
{
	long n;
	cin >> n;
	for (long i = 0; i < n; ++i)
	{
		cin >> a[i].first;
		a[i].second = i + 1;
	}

	sort(a, a + n, greater<pair<long, long> >());

	long long sum = 0;
	for (long i = 0; i < n; ++i) sum += a[i].first * i + 1;

	cout << sum << '\n';
	for (long i = 0; i < n; ++i) cout << a[i].second << ' ';
	return 0;
}
    