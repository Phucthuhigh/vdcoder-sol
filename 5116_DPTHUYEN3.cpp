// DPTHUYEN3

#include <iostream>
#include <algorithm>
#define ff first
#define ss second
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = (int)1e5 + 9;
int n, a[N], b[N], cnt;
pii xy[N];

template <typename T>
inline void readInt(T& num) {
	register char c = getchar();
	while (c != '-' && (c < '0' || '9' < c)) c = getchar();
	bool neg = false;
	if (c == '-') neg = true, c = getchar();
	for (num = 0; '0' <= c && c <= '9'; c = getchar()) num = (num << 1) + (num << 3) + c - '0';
	if (neg) num = -num;
}

void input() {
	readInt(n); for (int i = 1; i <= n; ++i) readInt(xy[i].ff), readInt(xy[i].ss);
	sort(xy + 1, xy + n + 1, [](const pii& x, const pii& y) {
		return (x.ff < y.ff || (x.ff == y.ff && x.ss > y.ss));
	});
	for (int i = 1; i <= n; ++i) a[i] = xy[i].ss;
}

int lis() {
	for (int i = 1, pos; i <= n; ++i) {
		pos = lower_bound(b, b + cnt, a[i]) - b;
		if (pos == cnt) b[cnt++] = a[i];
		else b[pos] = a[i];
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	input();
	cout << n - lis();
}
    