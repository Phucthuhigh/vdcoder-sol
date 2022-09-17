// DPCOING

#include <iostream>

using namespace std;

long long k, l, m, n;
bool a[1000002]; // a[i] ? 'A' : 'B'

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> k >> l >> m;
	
	a[1] = true;
	
	for (int i = 2; i <= 1000000; ++i)
	{
		a[i] = (
			(a[i - 1] == false) ||
			(i - k >= 0 && a[i - k] == false) ||
			(i - l >= 0 && a[i - l] == false));
	}

	while (m--)
	{
		cin >> n;
		cout << (a[n] ? 'A' : 'B');
	}

	return 0;
}
    