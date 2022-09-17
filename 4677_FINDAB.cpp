// FINDAB

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long n;
vector <long long> a, b;
bool bsearch(long long k)
{
   long l = 0, r = n - 1, mid;
   while (l <= r)
   {
      mid = (l + r) / 2;
      if (b[mid] == k) return true;
      if (b[mid] > k) r = mid - 1;
      else l = mid + 1;
   }
   return false;
}
int main()
{
   cin >> n;
   a.resize(n);
   b.resize(n);
   for (long i = 0; i < n; ++i) cin >> a[i];
   for (long i = 0; i < n; ++i) cin >> b[i];
   sort(b.begin(), b.end());
   long long dem = 0;
   for (long i = 0; i < n; ++i)
      if (bsearch(a[i])) ++dem;
   cout << dem;
   return 0;
}
    