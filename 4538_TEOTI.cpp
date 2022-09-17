// TEOTI

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
   long long n;
   vector<long long> a;
   cin >> n;
   a.resize(n);
   for (long i = 0; i < n; ++i) cin >> a[i];
   sort(a.begin(), a.end());
   cout << a[(n + 1) / 2 - 1];
   return 0;
}
    