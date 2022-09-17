// BTKCOW2

#include <iostream>
#include <string>

using namespace std;

long long a[20], n;
string s;
bool flag = true;


long long tong(long long k)
{
	s = "";
	long long res = 0;
	
	for (int i = 0; k > 0; ++i, k /= 2)
	{
		if (k % 2 == 1)
		{
			res += a[i];
			s += '2';
		}
		else s += '1';
	}
	while (s.size() < n) s += '1';
	return res;
}

int main()
{
	long long pown = 1, sum = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		pown *= 2;
		sum += a[i];
	}

	if (sum % 2 == 1) cout << -1;
	else
	{
		for (int i = 0; i < pown; ++i) if (tong(i) == sum / 2)
		{
			cout << s << '\n';
			flag = false;
		}
		if (flag) cout << -1;
	}
	return 0;
}
    