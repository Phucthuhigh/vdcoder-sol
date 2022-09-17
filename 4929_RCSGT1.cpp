// RCSGT1

#include <iostream>
using namespace std;
int main()
{
   long long n, res = 1;
   cin >> n;
   for (long i = 2; i <= n; ++i) res *= i;
   cout << res;
   return 0;
}
    