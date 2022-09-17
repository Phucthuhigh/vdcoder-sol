// PRODPRIME

#include <iostream>
#include <cmath>
using namespace std;
bool prime(long long k)
{
   if (k == 2 || k == 3 || k == 5) return 1;
   if (k < 2 || k % 2 == 0 || k % 3 == 0 || k % 5 == 0) return 0;
   for (long long i = 6; i < sqrt(k); i += 6)
      if (k % (i - 1) == 0 || k % (i + 1) == 0) return 0;
   return 1;
}
int main()
{
   long long n;
   cin >> n;
   if (prime(n + 1)) cout << "NO";
   else cout << "YES";
   return 0;
}
    