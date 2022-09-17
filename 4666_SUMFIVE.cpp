// SUMFIVE

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
   long long n, sum = 0;
   vector<long long> a;
   cin >> n;
   a.resize(n);
   for (long i = 0; i < n; ++i) cin >> a[i];
   sort(a.begin(), a.end());
   for (long i = 0; i < n && i < 5; ++i) sum += a[n - i - 1];
   cout << sum;
   return 0;
}
    