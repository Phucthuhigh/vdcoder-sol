// BOCBAI

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
   long long n, sum = 0, sumS = 0;
   vector<long long> a;
   cin >> n;
   a.resize(n);
   for (long i = 0; i < n; ++i) { cin >> a[i]; sum += a[i]; }
   sort(a.begin(), a.end());
   for (long i = n - 1; i >= 0; --i)
   {
      if ((n - i) % 4 == 1 || (n - i) % 4 == 0) sumS += a[i];
   }
   if (sum == sumS * 2) cout << "HOA";
   if (sum < sumS * 2) cout << "THANG";
   if (sum > sumS * 2) cout << "THUA";
   return 0;
}
    