// MaxofMin

#include <iostream>
using namespace std;
long long min_3(long long a, long long b, long long c)
{
   if (a > b) a = b;
   if (a > c) a = c;
   return a;
}
int main()
{
   ios_base::sync_with_stdio(false);
   long long n;
   long long a[3];
   cin >> n;
   if (n == 2) 
   {
      cin >> a[0] >> a[1];
      if (a[0] > a[1]) cout << a[1];
      else cout << a[0];
      return 0;
   }
   cin >> a[0] >> a[1] >> a[2];
   long long max = min_3(a[0], a[1], a[2]);
   for (long long i = 3, tmp; i < n; ++i)
   {
      cin >> a[i % 3];
      tmp = min_3(a[0], a[1], a[2]);
      if (max < tmp) max = tmp;
   }
   cout << max;
   return 0;
}
    