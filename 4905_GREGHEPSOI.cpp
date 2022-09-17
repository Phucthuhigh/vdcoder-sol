// GREGHEPSOI

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
long long x, y;
priority_queue<long long, vector<long long>, greater<long long>> q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n;
	for (int i = 0, a; i < n; ++i)
	{
		cin >> a;
		q.push(a);
	}
	
	long long sum = 0;
	while (q.size() > 1)
	{
		x = q.top(); q.pop();
		y = q.top(); q.pop();
		sum += x + y;
		q.push(x + y);
	}

	cout << sum;

	return 0;
}
    