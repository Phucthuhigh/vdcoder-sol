// DPDIFFARR

#include <iostream>
#include <vector>

using namespace std;

vector<long long> f(1000001, 0), a;

int main()
{
   ios_base::sync_with_stdio(false);
   long n, m;
   cin >> n >> m;
   a.resize(n + 1);
   for (long i = 1, tmp; i <= n; ++i) cin >> a[i];
   for (long i = n, d = 0, tmp; i > 0; --i)
   {
      tmp = ++f[a[i]];
      if (tmp == 1) ++d;
      a[i] = d;
   }
   for (long i = 0, tmp; i < m; ++i)
   {
      cin >> tmp;
      cout << a[tmp] << '\n';
   }
   return 0;
}
    