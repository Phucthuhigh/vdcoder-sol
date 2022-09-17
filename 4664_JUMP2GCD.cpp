// JUMP2GCD

#include <iostream>
using namespace std;
long long gcd(long long a, long long b)
{
   if (a == 0) return b;
   return gcd(b % a, a);
}
int main()
{
   long long n, k, d1, d2, d, dem = 0;
   cin >> n >> k >> d1 >> d2;
   d = gcd(d1, d2);
   for (long long i = 0, x; i < n; ++i)
   {
      cin >> x;
      if ((x - k) % d == 0) ++dem;
   }
   cout << dem;
}
    