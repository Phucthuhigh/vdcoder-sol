// STRXRING

#include <iostream>
#include <cstring>
#include <chrono>
#include <random>
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
const int N = (int)2e5 + 8;
struct node {
	node* l, * r;
	int cnt, prio;
	char c;
	bool rev;
	node(char ch, int len, int pr) : c(ch), cnt(len), prio(pr), rev(false) {}
} *root, * ll, * mm, * rr;
int n, m;
char s[N];

int tme;
node* buildTreap(int l, int r) {
	if (l > r) return NULL;
	int mid = (l + r) >> 1, new_id = ++tme;
	node* u = new node(s[mid], r - l + 1, N - (++tme));
	u->l = buildTreap(l, mid - 1);
	u->r = buildTreap(mid + 1, r);
	return u;
}

void rev(node* u) { if (u) u->rev ^= true; }
void push(node* u) {
	if (u && u->rev) {
		swap(u->l, u->r); u->rev = false;
		rev(u->l), rev(u->r);
	}
}
int getCnt(node* u) { return u ? u->cnt : 0; }
void pull(node* u) { u->cnt = getCnt(u->l) + getCnt(u->r) + 1; }
void split(node* u, node* &ll, node* &rr, int cnt) {
	if (!u) return void(ll = rr = 0);
	push(u);
	if (getCnt(u->l) >= cnt) {
		split(u->l, ll, u->l, cnt);
		rr = u;
	}
	else {
		split(u->r, u->r, rr, cnt - getCnt(u->l) - 1);
		ll = u;
	}
	pull(u);
}

void merge(node* &u, node* l, node* r) {
	push(l), push(r);
	if (!l || !r) u = l ? l : r;
	else if (l->prio > r->prio) {
		merge(l->r, l->r, r);
		u = l;
	}
	else {
		merge(r->l, l, r->l);
		u = r;
	}
	pull(u);
}

void reverse(int l, int r) {
	if (l >= r) return;
	split(root, ll, rr, r);
	split(ll, ll, mm, l - 1);
	rev(mm);
	merge(root, ll, mm);
	merge(root, root, rr);
}

void printTreap(node* u) {
	push(u);
	if (u->l) printTreap(u->l);
	putchar(u->c);
	if (u->r) printTreap(u->r);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> s; n = strlen(s);
	root = buildTreap(0, n - 1);

	int q, l, r, k; cin >> q;
	while (q-- > 0) {
		cin >> l >> r >> k;
		k %= (r - l + 1);
		if (k == 0) continue;

		reverse(l, r - k);
		reverse(r - k + 1, r);
		reverse(l, r);
	}

	printTreap(root);
}
    