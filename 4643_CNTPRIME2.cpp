// CNTPRIME2

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

const int N = (int)1e6;
int a, b, cntP, prime[N];
bool check[N], check2[N];

void sieve1()
{
	int canb = sqrt(b);
	prime[++cntP] = 2;
	for (int i = 3; i <= canb; i += 2)
	{
		if (!check[i])
		{
			check[i] = true;
			prime[++cntP] = i;
		}

		for (int j = 1; j <= cntP && prime[j] <= i && i * prime[j] <= canb; ++j)
			check[i * prime[j]] = true;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> a >> b;
	if (a <= 1 && b <= 1) { cout << 0; return 0; }
	a = max(a, 2);

	sieve1();
	for (long i = 1, j; i <= cntP; ++i)
	{
		j = (a + prime[i] - 1) / prime[i] * prime[i];
		if (j == prime[i]) j <<= 1;
		for (j -= a; j <= b - a; j += prime[i]) check2[j] = true;
	}

	int cnt = 0;
	for (int i = 0; i <= b - a; ++i)
		if (!check2[i]) ++cnt;
	cout << cnt;
	return 0;
}
    