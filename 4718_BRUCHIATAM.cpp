// BRUCHIATAM

#include <iostream>
#include <string>
using namespace std;
string n, k;
string min(const string& x, const string& y) 
{
	if (x.size() < y.size()) return x;
	if (x.size() > y.size()) return y;
	if (x < y) return x; return y;
}
int main()
{
	cin >> n;
	string minn = "aaaa";

	if (n.size() > 0)
	{
		for (long i = 0; i < n.size(); ++i)
		{
			long t = n[i] - '0';
			k = n[i];
			if (t % 8 == 0) minn = min(minn, k);
		}
	}

	if (n.size() > 1)
	{
		for (long i = 0; i < n.size() - 1; ++i)
		{
			for (long j = i + 1; j < n.size(); ++j)
			{
				long t = (n[i] - '0') * 10 + (n[j] - '0');
				k = n[i];
				k = k + n[j];
				if (t % 8 == 0) minn = min(minn, k);
			}
		}
	}

	if (n.size() > 2)
	{
		for (long i = 0; i < n.size() - 2; ++i)
		{
			for (long j = i + 1; j < n.size() - 1; ++j)
			{
				for (long z = j + 1; z < n.size(); ++z)
				{
					long t = (n[i] - '0') * 100 + (n[j] - '0') * 10 + (n[z] - '0');
					k = n[i];
					k = k + n[j];
					k = k + n[z];
					if (t % 8 == 0) minn = min(minn, k);
				}
			}
		}
	}

	if (minn == "aaaa") minn = "NO";
	cout << minn;
	return 0;
}
    