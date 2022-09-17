// TimAtrongB

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long n;
vector<long long> a, b;
bool searchB(long long k)
{
   long long l = 0, r = n - 1, mid;
   while (l <= r)
   {
      mid = (l + r) / 2;
      if (b[mid] == k) return 1;
      else
      {
         if (b[mid] > k) r = mid - 1;
         else l = mid + 1;
      }
   }
   return 0;
}
int main()
{
   long long dem = 0;
   cin >> n;
   a.resize(n);
   b.resize(n);
   for (long i = 0; i < n; ++i) cin >> a[i];
   for (long i = 0; i < n; ++i) cin >> b[i];
   for (long i = 0; i < n; ++i)
      if (searchB(a[i])) ++dem;
   cout << dem;
   return 0;
}
    