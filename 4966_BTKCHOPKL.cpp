// BTKCHOPKL

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long k, n, dem = 0;
vector<long long> a, b;
vector<bool> check(8, true);
void xuly()
{
   if (b.size() == k)
   {
      for (long i = 0; i < k; ++i) cout << b[i] << ' ';
      cout << '\n';
      ++dem;
   }
   else
   {
      for (long i = 0; i < n; ++i)
      {
         if (check[i])
         {
            b.push_back(a[i]);
            check[i] = false;
            xuly();
            b.pop_back();
            check[i] = true;
         }
      }
   }
}
int main()
{
   cin >> k >> n;
   a.resize(n);
   for (long i = 0; i < n; ++i) cin >> a[i];
   sort(a.begin(), a.end());
   xuly();
   cout << dem;
}
    