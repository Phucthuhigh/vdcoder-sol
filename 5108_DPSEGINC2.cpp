// DPSEGINC2

#include <iostream>
#include <stack>
#define ff first
#define ss second
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = (int)2e5 + 6;
int n, dp[N], trace[N], id[N], traceId[N], dp2[N];

void update(int num, int p) {
	int tmp = 1, traceTmp = 0;
	for (int i = 1, j; i * i <= num; ++i) {
		if (num % i == 0) {
			j = num / i;
			if (tmp <= dp[i]) {
				tmp = dp[i] + 1;
				traceTmp = i;
			}
			if (tmp <= dp[j]) {
				tmp = dp[j] + 1;
				traceTmp = j;
			}
		}
	}

	traceId[p] = id[traceTmp];
	dp2[p] = max(dp[num], tmp);

	if (dp[num] < tmp) {
		dp[num] = tmp;
		trace[num] = traceTmp;
		id[num] = p;
	}
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for (int i = 1, a; i <= n; ++i) {
		cin >> a;
		update(a, i);
	}

	int pos = 0;
	for (int i = 1; i < N; ++i)
		if (dp2[pos] < dp2[i]) pos = i;
		
	stack<int> ans;
	while (pos != 0) {
		ans.push(pos);
		pos = traceId[pos];
	}

	cout << ans.size() << '\n';
	while (!ans.empty()) cout << ans.top() << ' ', ans.pop();
	return 0;
}
    