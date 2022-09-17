// BTKEXP2

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

struct Bignum {
    int a[100], len;
    bool neg;
    Bignum(ll k) {
        fill(a, a + 100, 0); len = 0;
        if (k < 0) neg = true, k = -k;
        else neg = false;
        if (k == 0) len = 1;
        else while (k) a[len++] = k % 10, k /= 10;
    }
    Bignum() { fill(a, a + 100, 0); len = 0; };
} m, a[11];
int n, num[11], x[11];

#define maximize(a, b) if (a < b) a = b;
void operator += (Bignum& A, Bignum B) {
    maximize(A.len, B.len);

    int rem = 0; // remembrance
    for (int i = 0; i < A.len; ++i) {
        A.a[i] += B.a[i] + rem;
        rem = A.a[i] / 10;
        A.a[i] %= 10;
    }
    if (rem) A.a[A.len++] = rem;
}

void operator -= (Bignum& A, Bignum B) {
    int rem = 0;
    for (int i = 0; i < A.len; ++i) {
        A.a[i] -= B.a[i] + rem;
        if (A.a[i] < 0) A.a[i] += 10, rem = 1;
        else rem = 0;
    }
    while (A.len > 1 && A.a[A.len - 1] == 0) --A.len;
}

void operator *= (Bignum& A, Bignum B) {
    Bignum C; C.neg = A.neg;

    C.len = A.len + B.len - 1;
    for (int i = 0; i < A.len; ++i)
        for (int j = 0; j < B.len; ++j) C.a[i + j] += A.a[i] * B.a[j];

    int rem = 0;
    for (int i = 0; i < C.len; ++i) {
        C.a[i] += rem;
        rem = C.a[i] / 10;
        C.a[i] %= 10;
    }
    if (rem) C.a[C.len++] = rem;
    while (C.len > 1 && C.a[C.len - 1] == 0) --C.len;
    A = C;
}

short cmp(Bignum A, Bignum B) {
    if (A.len > B.len) return -1;
    if (A.len < B.len) return 1;

    for (int i = A.len - 1; i >= 0; --i) {
        if (A.a[i] > B.a[i]) return -1;
        if (A.a[i] < B.a[i]) return 1;
    }
    return 0;
}

void Plus(Bignum& A, Bignum B) {
    if (A.neg == B.neg) A += B;
    else if (cmp(A, B) == 1) { B -= A; A = B; }
    else A -= B;
}

void Sub(Bignum& A, Bignum B) {
    if (A.neg == B.neg) {
        if (cmp(A, B) == 1) {
            B -= A; A = B;
            A.neg = !A.neg;
        }
        else A -= B;
    }
    else A += B;
}

void Mul(Bignum& A, Bignum B) {
    A.neg = (A.neg != B.neg);
    A *= B;
}

#include <deque>
#define ff first
#define ss second
void check() {
    Bignum S1;
    deque<pair<Bignum, char>> q;
    q.emplace_back(a[1], '+');

    for (int i = 2; i <= n; ++i) {
        if (x[i] == 0) q.back().ff *= a[i];
        else if (x[i] == 1) q.emplace_back(a[i], '+');
        else q.emplace_back(a[i], '-');
    }

    while (!q.empty()) {
        if (q.front().ss == '-') Sub(S1, q.front().ff);
        else Plus(S1, q.front().ff);
        q.pop_front();
    }

    if (cmp(S1, m) == 0 && S1.neg == m.neg) {
        cout << num[1];
        for (int i = 2; i <= n; ++i) {
            cout << (x[i] == 0 ? '*' : (x[i] == 1 ? '+' : '-')) << num[i];
        }
        cout << '\n';
    }
}

void Try(int cnt) {
    if (cnt > n) return check();
    for (x[cnt] = 0; x[cnt] < 3; ++x[cnt]) Try(cnt + 1);
}

ll k;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> k; m = Bignum(k);
    for (int i = 1; i <= n; ++i) cin >> num[i], a[i] = Bignum(num[i]);
    Try(2);
}
    