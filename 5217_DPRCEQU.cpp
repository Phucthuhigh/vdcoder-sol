// DPRCEQU

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define mp make_pair

using namespace std;
typedef long long ll;

const int N = 1007, oo = (int)1e9 + 7;
int n, s, dp[N][N * 5];
bool avail[N][N * 5];
string a;

int cal(int cnt, int num)
{
	if (cnt == n) return (num == 0 ? 0 : oo);
	if (avail[cnt][num]) return dp[cnt][num];

	avail[cnt][num] = true;
	dp[cnt][num] = oo;

	for (int i = cnt, sum = 0; i < n; ++i)
	{
		(sum *= 10) += a[i] - '0';
		if (sum > num) break;
		dp[cnt][num] = min(dp[cnt][num], cal(i + 1, num - sum) + 1);
	}

	return dp[cnt][num];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	getline(cin, a, '='); n = a.size();
	cin >> s;
	
	cout << cal(0, s) - 1;

	return 0;
}
    