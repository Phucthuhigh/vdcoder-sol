// DPRCCOI

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

long long dp[1000006];
unordered_map<int, long long> mymap;

long long RC(int i)
{
	if (mymap.find(i) == mymap.end())
		mymap[i] = max((long long)i, RC(i >> 1) + RC(i / 3) + RC(i >> 2));
	return mymap[i];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	mymap[0] = 0;

	int n;
	while (cin >> n)
	{
		cout << RC(n) << '\n';
	}

	return 0;
}
    