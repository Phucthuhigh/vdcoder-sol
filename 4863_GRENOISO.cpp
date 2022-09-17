// GRENOISO

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a[200];
int main()
{
	long n = 0;

	while (cin >> a[n++]);

	sort(a, a + n, [](const string &x, const string &y) {	return (x + y > y + x || (x + y == y + x && x.size() < y.size()));	} );

	for (long i = 0; i < n; ++i) cout << a[i];

	return 0;
}
    