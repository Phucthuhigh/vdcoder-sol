// GIFT

#include <iostream>
using namespace std;
void swap(unsigned long long &a, unsigned long long &b)
{
   unsigned long long tmp = a;
   a = b;
   b = tmp;
}
int main()
{
   unsigned long long n, x, y, u, v, t;
   cin >> n;
   for (unsigned long long i = 0; i < n; ++i)
   {
      cin >> x >> y >> u >> v >> t;
      if (u < v) { swap(x, y); swap(u, v); }
      if (u > v + t) cout << x * (v + t) + y * v;
      else cout << x * u + y * v;
      cout << '\n'; 
   }
   return 0;
}
    