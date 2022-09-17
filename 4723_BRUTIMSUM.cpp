// BRUTIMSUM

#include <iostream>
#include <vector>
using namespace std;
int main()
{
   long n, q;
   vector<long long> a;
   long long sum = 0;
   cin >> n >> q;
   a.resize(n + 1);
   a[0] = 0;
   for (long i = 1, tmp; i <= n; ++i)
   {
      cin >> tmp;
      sum += tmp;
      a[i] = sum;
   }
   for (long i = 0, l , r; i < q; ++i)
   {
      cin >> l >> r;
      cout << a[r] - a[l - 1] << '\n';
   }
   return 0;
}
    