// FINDNEWPOS

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long n;
long t, res = 0;
vector <long long> a;
long bsearch(long long k)
{
   long l = 0, r = n - 1, mid, res_ = 0;
   while (l <= r)
   {
      mid = (l + r) / 2;
      if (a[mid] == k)
      {
         res_ = mid; 
         r = mid - 1;
      }
      else
      {
         if (a[mid] > k) r = mid - 1;
         else l = mid + 1;
      }
   }
   return res_;
}
int main()
{
   cin >> n >> t;
   --t;
   a.resize(n);
   for (long i = 0; i < n; ++i) cin >> a[i];
   for (long i = 0; i < t; ++i) if (a[i] == a[t]) ++res;
   long long tmp = a[t];
   sort(a.begin(), a.end());
   cout << bsearch(tmp) + res + 1;
   return 0;
}
    