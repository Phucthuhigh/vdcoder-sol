// BTKTACH

#include <iostream>
#include <string>
#include <stack>
using namespace std;
int n, top, path[42], m;
string s;
bool was[42];

void Try(int i) {
	if (i == m) {
		if (top == n) {
			for (int i = 1; i <= n; ++i) cout << path[i] << ' ';
			cout << '\n';
		}
		return;
	}

	if (s[i] == '0') return;
	if (!was[s[i] - '0']) {
		was[s[i] - '0'] = true;
		path[++top] = s[i] - '0';
		Try(i + 1);
		was[s[i] - '0'] = false;
		--top;
	}

	if (i + 1 < m) {
		int num = (s[i] - '0') * 10 + s[i + 1] - '0';
		if (num <= n && !was[num]) {
		was[num] = true;
		path[++top] = num;
		Try(i + 2);
		was[num] = false;
		--top;
	}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> s; m = s.size();
	Try(0);
	return 0;
}
    