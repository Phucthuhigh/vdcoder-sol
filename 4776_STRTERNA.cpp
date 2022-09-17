// STRTERNA

#pragma GCC optimization ("O3")
#pragma GCC target("tune=native")
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
const int N = (int)1e4 + 6;
int n, cnt[3], a[3][3];
string s;

void init() {
	if (cnt[0] > n / 3 && cnt[1] > n / 3) {
		a[0][2] = cnt[0] - n / 3;
		a[1][2] = cnt[1] - n / 3;
		return;
	}

	if (cnt[0] > n / 3 && cnt[2] > n / 3) {
		a[0][1] = cnt[0] - n / 3;
		a[2][1] = cnt[2] - n / 3;
		return;
	}

	if (cnt[1] > n / 3 && cnt[2] > n / 3) {
		a[1][0] = cnt[1] - n / 3;
		a[2][0] = cnt[2] - n / 3;
		return;
	}

	if (cnt[0] > n / 3) {
		a[0][1] = n / 3 - cnt[1];
		a[0][2] = n / 3 - cnt[2];
		return;
	}

	if (cnt[1] > n / 3) {
		a[1][0] = n / 3 - cnt[0];
		a[1][2] = n / 3 - cnt[2];
		return;
	}

	if (cnt[2] > n / 3) {
		a[2][0] = n / 3 - cnt[0];
		a[2][1] = n / 3 - cnt[1];
		return;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> s;
	for (char& c : s) ++cnt[c - '0'];
	init();
	for (int x = 0; x < 3; ++x) {
		for (int y = 0; y < x; ++y) { /// x->y
			for (int i = 0; a[x][y] && i < s.size(); ++i)
				if (s[i] == x + '0') s[i] = y + '0', --a[x][y];
		}

		for (int y = 2; y > x; --y) {
			for (int i = s.size() - 1; a[x][y] && i >= 0; --i)
				if (s[i] == x + '0') s[i] = y + '0', --a[x][y];
		}
	}
	cout << s;
	return 0;
}
    