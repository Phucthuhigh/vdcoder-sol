// STRCATSTR

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s, check = "cat";
	cin >> s;

	long long d = 0;
	for (long i = 0, n = s.size(), ite = 0, pre = 0; i < n; ++i)
	{
		if (s[i] == check[ite])
		{
			++ite;
			if (ite == 3)
			{
				d += 1LL * (i - pre - 1) * (n - i);
				pre = i - 1;
				ite = 0;
			}
		}
		else
		{
			ite = 0;
			if (s[i] == check[ite]) ++ite;
		}
	}
	
	cout << d;
	return 0;
}
    