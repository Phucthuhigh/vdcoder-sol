// SORTPRIME

#include <iostream>
using namespace std;
bool check[200001];
long n, dem1, dem2;
void sieve()
{
	for (long long i = 3; i < 200001; i += 2)
		if (!check[i])
		{
			 for (long long j = i * i; j < 200001; j += 2 * i) check[j] = true;
		}
}
int main()
{
	cin >> n;
	long t = n, tmp;
	while (t--)
	{
		cin >> tmp;
		if (tmp == 1) ++dem1;
		if (tmp == 2) ++dem2;
	}
	sieve();
	if (dem1 == 0)
	{
		if (dem2 == 0) cout << 0;
		else cout << 1;
	}
	else
	{
		if (dem2 == 0)
		{
			long d = 0;
			if (dem1 >= 2) ++d;
			for (long i = 3; i <= dem1; i += 2) if (!check[i]) ++d;
			cout << d;
		}
		else
		{
			long d = 2, i = 5;
			dem2 += (dem1 - 1) / 2 - 1;
			for ( ; i <= dem2 * 2 + 3; i += 2) if (!check[i]) ++d;
			cout << d;
		}
	}
	return 0;
}
    