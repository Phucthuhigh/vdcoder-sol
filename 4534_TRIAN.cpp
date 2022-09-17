// TRIAN

#include <iostream>
#include <vector>
using namespace std;
int main()
{
   long long n, k, res;
   vector<long long> a;
   cin >> n;
   a.resize(n);
   for (long i = 0; i < n; ++i) cin >> a[i];
   cin >> k;
   for (res = 0; res < n; ++res) if (a[res] == k) break;
   cout << res + 1;
   return 0;
}
    