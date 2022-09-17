// GRECUTSEG

#include <iostream>
#include <utility>
#include <deque>
#include <unordered_set>

using namespace std;

int n, l;
unordered_set<int> myset;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int t;
	cin >> t;
	while (t--)
	{
		myset.clear();
		deque<pair<int, int>> q;
		cin >> n;
		for (int i = 1, l = 1, a; i <= n; ++i)
		{
			cin >> a;
			if (myset.find(a) != myset.end())
			{
				q.push_back({ l, i });
				myset.clear();
				l = i + 1;
			}
			else myset.insert(a);
		}
		if (q.empty()) cout << "-1\n";
		else
		{
			q.back().second = n;
			while (!q.empty())
			{
				cout << q.front().first << ' ' << q.front().second << '\n';
				q.pop_front();
			}
		}
	}

	return 0;
}
    