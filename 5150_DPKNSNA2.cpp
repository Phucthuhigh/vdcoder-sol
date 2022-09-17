// DPKNSNA2

#pragma GCC optimize ("O3")
#pragma GCC optimization ("unroll-loops")
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 9;
typedef long long ll;
int m, n;
ll f[N];

inline void read(int& x) {
	register char c = getchar();
	while (!isdigit(c)) c = getchar();
	x = c ^ 48;
	while (isdigit(c = getchar())) x = (x << 3) + (x << 1) + (c ^ 48);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	read(m);
	read(n);
	for (int i = 0, v, w; i < n; ++i) {
		read(v);
		read(w);
		for (int j = w; j <= m; ++j) if (f[j] < f[j - w] + v) f[j] = f[j - w] + v;
	}
	cout << f[m];
}
    