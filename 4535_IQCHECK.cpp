// IQCHECK

#include <iostream>
#include <vector>
using namespace std;
int main()
{
   long long n, chan_dem = 0, k;
   vector<long long> a;
   cin >> n;
   a.resize(n);
   for (long i = 0; i < n; ++i) 
   {
      cin >> a[i];
      if (a[i] % 2 == 0) ++chan_dem;
   }
   if (chan_dem == 1) k = 0;
   else k = 1;
   for (long i = 0; i < n; ++i)
     if (a[i] % 2 == k) {cout << a[i]; break; }
   return 0;
}
    