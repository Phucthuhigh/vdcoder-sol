// STRROOTSTR

#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;
typedef long long ll;

const int N = (int)1e6 + 5, mod = (int)1e9 + 7;
int n;
bool t[26];
string s;
unordered_set<int> myset;

int hashh(const string& s)
{
	for (int i = 0; i < 26; ++i) t[i] = false;
	for (char c : s)
		t[c - 'a'] = true;
	int res = 0;
	for (int i = 0; i < 26; ++i)
		if (t[i]) res |= 1 << i;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> s;
		myset.insert(hashh(s));
	}
	cout << myset.size();
	return 0;
}
    