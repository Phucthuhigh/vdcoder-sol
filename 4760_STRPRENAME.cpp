// STRPRENAME

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = (int)2e5 + 8;
int n, a[26][N], cnt[26];
string s;

void enter() {
	cin >> n;
	char c;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 26; ++j) a[j][i] = a[j][i - 1];
		cin >> c;
		++a[c - 'a'][i];
	}
}

bool check(int mid) {
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] > a[i][mid]) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	enter();
	int m; cin >> m; while (m-- > 0) {
		fill(cnt, cnt + 26, 0);
		cin >> s;
		for (char c : s) ++cnt[c - 'a'];

		if (!check(n)) {
			cout << -1 << '\n';
			continue;
		}

		int mid, l = 1, r = n - 1;
		while (l <= r) {
			mid = (l + r >> 1);
			if (check(mid)) r = mid - 1;
			else l = mid + 1;
		}
		cout << r + 1 << '\n';
	}
	return 0;
}
    