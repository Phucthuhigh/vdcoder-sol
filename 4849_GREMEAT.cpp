// GREMEAT

#include <iostream>
#include <utility>
using namespace std;
pair<long, long> a[100000];

int main()
{
	long n;
	cin >> n >> a[0].first >> a[0].second;
	long tmp = a[0].second;
	for (long i = 1; i < n; ++i)
	{
		cin >> a[i].first >> a[i].second;
		if (tmp < a[i].second) a[i].second = tmp;
		else tmp = a[i].second;
	}

	long long sum = 0;
	for (long i = 0; i < n; ++i) sum += 1LL * a[i].first * a[i].second;

	cout << sum;
	return 0;
}
    