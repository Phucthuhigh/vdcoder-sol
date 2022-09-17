// STRNEWS

#pragma GCC optimization ("O3")
#pragma GCC target("tune=native")
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
const int N = (int)1e4 + 6;
int next_char[N][26], tmp[26];
string s1, s2;
bool avail[26];

void init_next_char() {
	for (int i = s1.size() - 1; i >= 0; --i) {
		for (int j = 0; j < 26; ++j) next_char[i][j] = tmp[j];
		tmp[s1[i] - 'a'] = i;
	}
	for (int i = s1.size() - 1; i >= 0; --i) {
		for (int j = 0; j < 26; ++j)
			if (next_char[i][j] == 0) next_char[i][j] = tmp[j];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> s1 >> s2;
	for (char c : s1) avail[c - 'a'] = true;
	for (char c : s2)
		if (!avail[c - 'a']) {
			cout << -1;
			return 0;
		}
	init_next_char();

	int ans = 0, p = s1.size() - 1;
	for (char c : s2) {
		if (next_char[p][c - 'a'] <= p) ++ans;
		p = next_char[p][c - 'a'];
	}
	cout << ans;
	return 0;
}
    