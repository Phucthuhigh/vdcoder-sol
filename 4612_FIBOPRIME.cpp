// FIBOPRIME

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<long long> fib;
long long bsearch(long long k)
{
   long l = 0, r = fib.size() - 1, mid, res = -1;
   while (l <= r)
   {
      mid = (l + r) / 2;
      if (fib[mid] == k) return mid;
      if (fib[mid] > k) r = mid - 1;
      else { l = mid + 1; res = mid; }
   }
   return res;
}
bool prime(long long k)
{
   if (k == 2 || k == 3 || k == 5) return 1;
   if (k < 2 || k % 2 == 0 || k % 3 == 0 || k % 5 == 0) return 0;
   for (long long i = 6; i < sqrt(k); i += 6)
      if (k % (i - 1) == 0 || k % (i + 1) == 0) return 0;
   return 1;
}
void set_fib()
{
   fib.push_back(2); 
   fib.push_back(3);
   long long lim = 1000000000000000;
   while (fib.back() < lim)
   {
      fib.push_back(fib.back() + fib[fib.size() - 2]);
   }
   for (long i = 0; i < fib.size(); )
   {
      if (prime(fib[i])) ++i;
      else fib.erase(fib.begin() + i);
   }
}
int main()
{
   set_fib();
   
   long long a, b;
   cin >> a >> b;
   long long l = bsearch(a - 1), r = bsearch(b);
   cout << r - l;
   return 0;
}
    