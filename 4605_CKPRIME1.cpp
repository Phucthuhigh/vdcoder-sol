// CKPRIME1

#include <bits/stdc++.h>
using namespace std;

bool check_prime(long long n) {
	if (n <= 5) return n == 2 || n == 3 || n == 5;
	if (n < 2 || n % 2 == 0 || n % 3 == 0 || n % 5 == 0) return false;
	for (long long i = 5; i*i <= n; i+=6) {
		if (n % i == 0 || n % (i+2) == 0) return false;
	}
	return true;
}

int main() {
	long long n; cin >> n;
	cout << (check_prime(n) ? "YES" : "NO");
	return 0;
}
    