// DPLCSMA

#include <iostream>
#include <string>

using namespace std;

const int N = 1003;
int m, n;
string lcs[2][N], x, y;

string maxStr(const string& s1, const string& s2)
{
	if (s1.size() > s2.size()) return s1;
	if (s1.size() < s2.size()) return s2;
	for (int i = 0, len = s1.size(); i < len; ++i)
	{
		if (s1[i] > s2[i]) return s1;
		if (s1[i] < s2[i]) return s2;
	}
	return s1; // s1 = s2
}

string max_number(string& p, string& q) {
	if (p == "") return q;
	if (q == "") return p;
	string u = p, v = q;
	while (p.size() < q.size()) p = "0" + p;
	while (q.size() < p.size()) q = "0" + q;
	if (p > q) return u; else return v;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> x >> y; x = ' ' + x; y = ' ' + y;
	m = x.size(), n = y.size();
	for (int i = 1; i < m; ++i)
		for (int j = 1; j < n; ++j)
		{
			if (x[i] == y[j])
			{
//				if (lcs[(i - 1) & 1][j - 1] == "0")
//					lcs[(i - 1) & 1][j - 1].clear();
				lcs[i & 1][j] = lcs[(i - 1) & 1][j - 1] + x[i];
				continue;
			}
			// x[i] != y[j]
			lcs[i & 1][j] = max_number(lcs[(i - 1) & 1][j], lcs[i & 1][j - 1]);
		}

	string res = lcs[(m - 1) & 1][n - 1];

	int i = 0, len = res.size();
	while (i < len && res[i] == '0') ++i;
	
	if (i == len)
	{
		bool flagx = false, flagy = false;
		for (int j = 1; j < m; ++j) if (x[j] == '0') flagx = true;
		for (int j = 1; j < n; ++j) if (y[j] == '0') flagy = true;
		if (len == 0 || !(flagx && flagy))
			cout << "0\nLCS MAX NUMBER is NULL";
		else --i;
	}
	if (i < len)
	{
		cout << len - i << "\nLCS MAX NUMBER is ";
		while (i < len) cout << res[i++];
	}

//	cout << res.size() << '\n';
//	cout << "LCS MAX NUMBER is " << (res == "" ? "NULL" : res);

	return 0;
}
    