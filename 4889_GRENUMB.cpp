// GRENUMB

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = (int)2e5 + 8;
int n, m;
string a, b;
void enter() {
	cin >> a >> b; n = a.size(), m = b.size();
}

void check(int i) {
	if (a[i] < b[i] || i == n - 1) {
		sort(a.begin() + i + 1, a.end(), greater<char>());
		cout << a;
		exit(0);
	}
	sort(a.begin() + i + 1, a.end()); 
	for (int j = i + 1; j < n; ++j) {
		if (a[j] > b[j]) { // get a <= b in range [j, end)
			for (int k = i + 1; k < n; ++k)
				if (k == n - 1 || a[k + 1] >= b[i]) {
					swap(a[k], a[i]); // max element have a[k] < b[i]
					sort(a.begin() + i + 1, a.end(), greater<char>());
					if (a[i] == '0' && i == 0) cout << -1;
					else cout << a;
					exit(0);
				}
		}
		else if (a[j] < b[j]) break;
	}
}

void process() {
	if (m > n) {
		sort(a.begin(), a.end(), greater<char>());
		cout << a;
		return;
	}
	if (m < n) {
		cout << -1;
		return;
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; ++i) {
		if (a[i] > b[i]) { // check a <= b
			cout << -1;
			return;
		}
		if (a[i] < b[i]) break;
	}
	for (int i = 0, j; i < n; ++i) {
		j = upper_bound(a.begin() + i, a.end(), b[i]) - a.begin() - 1;
		swap(a[i], a[j]);
		check(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	enter();
	process();
}
    