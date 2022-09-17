// BRUDIAMETE

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long> x;
long n, d;
long bsearch(long long k)
{
   long l = 0, r = n - 1, mid, res = n - 1;
   while (l <= r)
   {
      mid = (l + r) / 2;
      if (x[mid] == k)
      {
         res = mid; 
         l = mid + 1;
      }
      else
      {
         if (x[mid] > k) r = mid - 1;
         else l = mid + 1;
      }
   }
   return res;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin >> n >> d;
   x.resize(n);
   for (long i = 0; i < n; ++i) cin >> x[i];
   sort(x.begin(), x.end());
   long max_ = 0;
   for (long i = 0, tmp; i < n; ++i)
   {
      tmp = bsearch(x[i] + d);
      if (x[tmp] - x[i] <= d && max_ < tmp - i + 1) max_ = tmp - i + 1;
   }
   cout << n - max_;
   return 0;
}
    