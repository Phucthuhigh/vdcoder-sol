// MISSINGPRI

#include <iostream>
//#include <vector>
using namespace std;
bool a[2000001], check[2000001];
long n, maxx = 0;
void sieve()
{
//	vector<bool> check(maxx + 1, false);
	for (long long i = 2; i <= maxx; ++i)
		if (!check[i])
		{
			if (a[i]) for (long long j = i * i; j <= maxx; j += i) check[j] = true;
			else
			{
				cout << i;
				return;
			}
		}
	cout << "No prime number missing!";
}
int main()
{
	cin >> n;
	for (long i = 0, t; i < n; ++i)
	{
		cin >> t;
		a[t] = true;
		if (maxx < t) maxx = t;
	}
	sieve();
	return 0;
}
    