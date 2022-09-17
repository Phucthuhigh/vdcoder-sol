// MANG513

#include <iostream>
#include <vector>
using namespace std;
int main()
{
   long long n, d = 0;
   vector<long long> a;
   cin >> n;
   a.resize(n);
   for (long i = 0; i < n; ++i) cin >> a[i];
   for (long long i = 0, tmp; i < n; ++i)
   {
      cin >> tmp;
      cout << a[i] << ' ' << tmp << ' ';
   }
   return 0;
}
    