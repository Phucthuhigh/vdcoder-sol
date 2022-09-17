// BTKCATU1

#include <iostream>
#include <vector>

using namespace std;
vector<long long> w, v;
long long n, m, maxx = 0;

void dequy(int pos, long long weigh, long long sum)
{
	if (pos == n)
	{
		if (maxx < sum) maxx = sum;
	}
	else
	{
		dequy(pos + 1, weigh, sum);
		if (weigh + w[pos] <= m) dequy(pos + 1, weigh + w[pos], sum + v[pos]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	w.resize(n);
	v.resize(n);
	for (int i = 0; i < n; ++i) cin >> w[i] >> v[i];

	dequy(0, 0, 0);

	cout << maxx;
	return 0;
}
    