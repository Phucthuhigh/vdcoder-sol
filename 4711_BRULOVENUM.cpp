// BRULOVENUM

#include <iostream>

using namespace std;

int main()
{
	long n, d4 = 0, d7 = 0;
	cin >> n;
	
	if (n >= 0 && n % 7 == 0) d7 = n / 7;
	if (n >= 4 && (n - 4) % 7 == 0) { d4 += 1; d7 = (n - 4) / 7; }
	if (n >= 8 && (n - 8) % 7 == 0) { d4 += 2; d7 = (n - 8) / 7; }
	if (n >= 12 && (n - 12) % 7 == 0) { d4 += 3; d7 = (n - 12) / 7; }
	if (n >= 16 && (n - 16) % 7 == 0) { d4 += 4; d7 = (n - 16) / 7; }
	if (n >= 20 && (n - 20) % 7 == 0) { d4 += 5; d7 = (n - 20) / 7; }
	if (n >= 24 && (n - 24) % 7 == 0) { d4 += 6; d7 = (n - 24) / 7; }
	
	if (d4 * 4 + d7 * 7 == n)
	{
		for (long i = 0; i < d4; ++i) cout << 4;
		for (long i = 0; i < d7; ++i) cout << 7;
	}
	else cout << -1;
}
    