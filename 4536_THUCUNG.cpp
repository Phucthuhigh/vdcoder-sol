// THUCUNG

#include <iostream>
#include <vector>
using namespace std;
int main()
{
   long long n, max = -1, sum = 0;
   vector<long long> a;
   cin >> n;
   a.resize(n);
   for (long i = 0; i < n; ++i) 
   {
      cin >> a[i];
      if (a[i] > max) max = a[i];
   }
   for (long i = 0; i < n; ++i)
      sum = sum + (max - a[i]);
   cout << sum;
   return 0;
}
    