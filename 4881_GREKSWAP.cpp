// GREKSWAP

#include <iostream>
#include <algorithm>

using namespace std;

int k;
string s;

void reserve(string& s, int first, int last)
{
	while (first < last)
	{
		swap(s[first], s[last]);
		++first, --last;
	}
}

int main()
{
	cin >> s >> k;
	int moc = 0, n = s.size();
	while (k > 0 && moc < n)
	{
		int ma = moc;
		for (int i = moc + 1; i < n && i - moc <= k; ++i)
		{
			if (s[i] > s[ma]) ma = i;
		}
		if (ma != moc)
		{
			k -= ma - moc;
			reserve(s, moc, ma - 1);
			reserve(s, moc, ma);
		}
		++moc;
	}

	cout << s;

	return 0;
}
    