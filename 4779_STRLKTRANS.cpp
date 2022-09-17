// STRLKTRANS

#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
const int N = (int)1e4 + 6;
int n, k;
string s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> k >> s; s = " " + s;
	for (int i = 1; i < n && k > 0; ++i)
		if (s[i] == '4' && s[i + 1] == '7') {
			--k;
			if (i & 1) s[i + 1] = '4';
			else {
				s[i] = '7';
				if (i > 1 && s[i - 1] == '4') {
					s[i] = (k & 1 ? '4' : '7');
					break;
				}
			}
		}
	for (int i = 1; i <= n; ++i) cout << s[i];
	return 0;
}
    