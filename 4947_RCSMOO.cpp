// RCSMOO

#include <iostream>
#include <string>

using namespace std;

int n;
long long dp[100005];

char find(int n, int k)
{
	if (n <= dp[k - 1]) return find(n, k - 1);
	n -= dp[k - 1];
	if (n > k + 2) return find(n - k - 2, k - 1);
	return (n == 1 ? 'm' : 'o');
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;

	dp[1] = 3;
	int k = 1;
	while (dp[k] < n)
	{
		dp[++k] = dp[k - 1] * 2 + k + 2;
	}
	cout << find(n, k);
	return 0;
}
    