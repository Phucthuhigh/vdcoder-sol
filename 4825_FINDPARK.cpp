// FINDPARK

#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int N = (int)2e5 + 5, oo = 1e9 + 7;
ll n, m, c1, c2;

ll cost(ll gr)
{ // c1 + c2 * (x - 1) ^ 2
	ll x_basic = n / gr; // so nguoi trong 1 nhom basic
	ll bonus = n % gr; // so nhom bonus them 1 nguoi
	return c1 * gr + c2 * bonus * x_basic * x_basic + c2 * (gr - bonus) * (x_basic - 1) * (x_basic - 1);
}
/*
n = 7, mid = 3
num = 7 / 3 = 2 => so nguoi trong 1 nhom basic
mod = 7 % 3 = 1 => so nhom them 1 nguoi
*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> c1 >> c2;
	int l = 1, r = m, mid1, mid2;
	ll cost1, cost2;
	while (r - l > 2)
	{
		mid1 = l + (r - l) / 3;
		mid2 = r - (r - l) / 3;
		cost1 = cost(mid1);
		cost2 = cost(mid2);
		if (cost1 == cost2)
		{
			l = mid1, r = mid2;
			continue;
		}

		if (cost1 > cost2)
			l = mid1;
		else
			r = mid2;
	}

	for (int i = l + 1; i <= r; ++i)
		if (cost(i) < cost(l)) l = i;
	cout << cost(l);

	return 0;
}
    