// DPTICK3

#include <iostream>
#include <algorithm>

using namespace std;

int n, s, f, desti[10004][3];
long long l1, l2, l3, c1, c2, c3, a[10004], dp[10004];

void input()
{
	cin >> l1 >> l2 >> l3 >> c1 >> c2 >> c3 >> n >> s >> f;
	for (int i = 2; i <= n; ++i) cin >> a[i];
}

void set_desti()
{
	for (int i = f, des1 = f, des2 = f, des3 = f; i > s; --i)
	{
		while (i > s && a[i] - a[des1 - 1] <= l1) --des1;
		while (i > s && a[i] - a[des2 - 1] <= l2) --des2;
		while (i > s && a[i] - a[des3 - 1] <= l3) --des3;
		desti[i][0] = des1;
		desti[i][1] = des2;
		desti[i][2] = des3;
	}
}

void processing()
{
	for (int i = s + 1; i <= f; ++i)
	{
		dp[i] = 1000000000;
		dp[i] = min(min(
			dp[desti[i][0]] + c1, 
			dp[desti[i][1]] + c2), 
			dp[desti[i][2]] + c3);
	}

	cout << dp[f];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	input();
	set_desti();
	processing();
	return 0;
}
    