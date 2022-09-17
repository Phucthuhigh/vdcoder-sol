// BTKEXP1

#include <iostream>
#include <stack>

using namespace std;

int n;
long long m, a[22], tmp;

long long get(int k)
{
	long long res = a[0];
	for (int i = n - 1; i > 0; --i)
	{
		if (k & 1) res += a[i];
		else res -= a[i];
		k >>= 1;
	}
	return res;
}

void output(int k)
{
	cout << a[0];

	stack<char> st;
	for (int i = n - 1; i > 0; --i)
	{
		st.push(k & 1 ? '+' : '-');
		k >>= 1;
	}
	for (int i = 1; i < n; ++i)
	{
		cout << st.top() << a[i];
		st.pop();
	}
	cout << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n >> m >> a[0];
	for (int i = 1; i < n; ++i)
	{
		cin >> tmp;
		a[i] = (tmp > 0 ? tmp : -tmp);
	}

	for (int i = (1 << n - 1) - 1; i >= 0; --i)
	{
		if (get(i) == m)
		{
			output(i);
		}
	}
	
	return 0;
}
    