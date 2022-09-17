// GREMAXARR

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;
typedef long long ll;
const int N = (int)2e5 + 7;
const ll oo = (ll)1e18 + 18;
int n, k;
ll x;

struct Data {
	ll val;
	int pos;
} a[N];

struct cmp1 {
	bool operator () (const Data& a, const Data& b) {
		return (a.val > b.val); // qmin
	}
};

struct cmp2 {
	bool operator () (const Data& a, const Data& b) {
		return (a.val < b.val); // qmax
	}
};

template<typename T>
bool fast_scan(T& num) {
	num = 0;
	register char c = getchar();
	while (c != '-' && (c < '0' || '9' < c)) {
		if (feof(stdin)) return false;
		c = getchar();
	}
	bool neg = false;
	if (c == '-') {
		neg = true;
		c = getchar();
	}
	for (; '0' <= c && c <= '9'; c = getchar()) num = (num << 1) + (num << 3) + (c - '0');
	if (neg) num = -num;
	return true;
}

priority_queue<Data, vector<Data>, cmp1> qmin;
priority_queue<Data, vector<Data>, cmp2> qmax;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	fast_scan(n), fast_scan(k), fast_scan(x);
//	cin >> n >> k >> x;
	for (int i = 1; i <= n; ++i)
	{
		fast_scan(a[i].val);
//		cin >> a[i].val;
		a[i].pos = i;

		if (a[i].val < 0) qmax.push(a[i]);
		else qmin.push(a[i]);
	}

	while ((qmax.size() % 2 == 0) && k > 0)
	{
		Data tmp1, tmp2;
		if (!qmin.empty()) tmp1 = qmin.top(); else tmp1.val = oo;
		if (!qmax.empty()) tmp2 = qmax.top(); else tmp2.val = -oo;
		if (tmp1.val < -tmp2.val)
		{
			qmin.pop();
			tmp1.val -= x;
			if (tmp1.val < 0) qmax.push(tmp1);
			else qmin.push(tmp1);
		}
		else
		{
			qmax.pop();
			tmp2.val += x;
			if (tmp2.val < 0) qmax.push(tmp2);
			else qmin.push(tmp2);
		}
		--k;
	}

	while (k > 0)
	{
		Data tmp1, tmp2;
		if (!qmin.empty()) tmp1 = qmin.top(); else tmp1.val = oo;
		if (!qmax.empty()) tmp2 = qmax.top(); else tmp2.val = -oo;
		if (tmp1.val < -tmp2.val)
		{
			qmin.pop();
			tmp1.val += x;
			qmin.push(tmp1);
		}
		else
		{
			qmax.pop();
			tmp2.val -= x;
			qmax.push(tmp2);
		}
		--k;
	}

	while (!qmin.empty())
	{
		a[qmin.top().pos] = qmin.top();
		qmin.pop();
	}

	while (!qmax.empty())
	{
		a[qmax.top().pos] = qmax.top();
		qmax.pop();
	}

	for (int i = 1; i <= n; ++i) cout << a[i].val << ' ';
	return 0;
}
    