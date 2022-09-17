// DPRCPER

#include <iostream>

using namespace std;
typedef long long ll;

const int N = 1e6 + 7;
int n, k, dp[15][100], avail[15][100];

int getRes(int num, int cnt)
{
	if (num == 0) return 0;
	if (cnt == 0) return 1;
	if (avail[num][cnt]) return dp[num][cnt];
	avail[num][cnt] = true;
	for (int i = 0; i <= min(num - 1, cnt); ++i)
		dp[num][cnt] += getRes(num - 1, cnt - i); // last num is num, num-1,num-2,...
	return dp[num][cnt];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int d;
	cin >> d;
	while (d-- > 0)
	{
		cin >> n >> k;
		cout << getRes(n, k) << '\n';
	}
	return 0;
}
    