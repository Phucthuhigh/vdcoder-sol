// GRESORTB

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;

const int N = (int)2e5 + 8;
int n, a[N];
multiset<int> b;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1, x; i <= n; ++i) cin >> x, b.insert(x);

	for (int i = 1; i <= n; ++i) {
		multiset<int>::iterator it = b.lower_bound(n - a[i]);
		if (it == b.end()) {
			cout << (a[i] + *b.begin()) % n << ' ';
			b.erase(b.begin());
		}
		else {
			cout << (a[i] + *it) % n << ' ';
			b.erase(it);
		}
	}

	return 0;
}
    