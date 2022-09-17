// PHATKEO3

#include <iostream>
using namespace std;
int main()
{
   long long n, sum;
   cin >> n;
   sum = (n / 2) * (1 + (n * 3 - 2)) + (n % 2) * ((n + 1) / 2 * 3 - 2);
   cout << sum << '\n';
   for (long long i = 0; i < n; ++i) cout << 3 * i + 1 << ' ';
   return 0;
}
    