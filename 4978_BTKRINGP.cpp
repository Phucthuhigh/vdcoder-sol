// BTKRINGP

#include <iostream>
#include <vector>

using namespace std;

int n;
bool prime[41] = { 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0 };
bool mark[21];
vector<int> a(1, 1);
void RC()
{
	if (a.size() == n)
	{
		if (prime[a[0] + a.back()])
		{
			for (int i = 0; i < n; ++i) cout << a[i] << ' ';
			cout << '\n';
		}
		return;
	}
	for (long i = (a.back() % 2 == 1 ? 2 : 3); i <= n; ++i)
	{
		if (!mark[i] && prime[a.back() + i])
		{
			a.push_back(i);
			mark[i] = true;
			
			RC();
			
			a.pop_back();
			mark[i] = false;
		}
	}
}
int main()
{
	cin >> n;

	n *= 2;
	
	mark[1] = true;
	RC();

	return 0;
}
    