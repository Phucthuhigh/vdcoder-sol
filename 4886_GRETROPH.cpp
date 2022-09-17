// GRETROPH

#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

const int N = (int)1e5 + 8;
int n, l[N], r[N], cnt;
string s;
char c;

#define max3(a, b, c) max(a, max(b, c))
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> s;

	int j = s.find_first_of('G'), i = (j == -1 ? n : j);
	while (i < n) {
		while (i < n && s[i] == 'G') ++i;
		l[cnt] = j, r[cnt] = i - 1, ++cnt;
		while (i < n && s[i] == 'S') ++i;
		j = i; // s[i] = 'G'
	}

	if (cnt == 0) {
		cout << 0; return 0;
	}

	if (cnt == 1) {
		cout << r[0] - l[0] + 1; return 0;
	}

	if (cnt == 2) {
		if (l[1] - r[0] == 2) cout << r[1] - l[0];
		else cout << max(r[0] - l[0] + 1, r[1] - l[1] + 1) + 1;
		return 0;
	}

	int ans = r[0] - l[0] + 2;
	for (int i = 1; i < cnt; ++i) {
		ans = max(ans, r[i] - l[i] + 2);
		if (l[i] - r[i - 1] == 2) ans = max(ans, r[i] - l[i - 1] + 1);
	}
	cout << ans;

	return 0;
}
    