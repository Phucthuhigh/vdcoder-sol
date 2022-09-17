// BTKCHOPL

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long k, n, dem = 0;
vector<long long> a, res;
vector<bool> check(8, true);
void xuly1()
{
   if (res.size() == k)
   {
      ++dem;
   }
   else
   {
      for (long i = 0; i < n; ++i)
      {
         res.push_back(i);
         xuly1();
         res.pop_back();
      }
   }
}
void xuly()
{
   if (res.size() == k)
   {
      for (long i = 0; i < k; ++i) cout << a[res[i]] << ' ';
      cout << '\n';
   }
   else
   {
      for (long i = 0; i < n; ++i)
      {
         res.push_back(i);
         xuly();
         res.pop_back();
      }
   }
}
int main()
{
   cin >> k >> n;
   a.resize(n);
   for (long i = 0; i < n; ++i) cin >> a[i];
   sort(a.begin(), a.end());
   xuly1();
   cout << dem << '\n';
   xuly();
   return 0;
}
    