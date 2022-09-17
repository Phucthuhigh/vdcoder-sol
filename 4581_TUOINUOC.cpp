// TUOINUOC

#include <iostream>
using namespace std;
long long max_(long long a, long long b) { if (a > b) return a; else return b; }
int main()
{
   long long n, k, pre, max;
   cin >> n >> k;
   cin >> pre;
   max = pre - 1;
   for (long long i = 1, tmp; i < k; ++i)
   {
      cin >> tmp;
      max = max_(max, (tmp - pre) / 2);
      pre = tmp;
   }
   max = max_(max, n - pre);
   cout << max + 1;
   return 0;
}
    