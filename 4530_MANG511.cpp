// MANG511

#include <iostream>
#include <vector>
using namespace std;
int main()
{
   long long n, d = 0;
   vector<double> a;
   cin >> n;
   a.resize(n);
   for (long i = 0; i < n; ++i) cin >> a[i];
   if (a[0] < a[1]) ++d;
   if (a[--n] < a[n - 1]) ++d;
   for (long i = 1; i < n; ++i)
      if (a[i] < a[i - 1] && a[i] < a[i + 1]) ++d;
   cout << d;
   return 0;
}
    