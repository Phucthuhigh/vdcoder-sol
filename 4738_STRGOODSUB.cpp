// STRGOODSUB

#include <iostream>
using namespace std;
int main()
{
   long n, k;
   char tmp;
   cin >> n >> k;
   int a[k];
   for (long i = 0; i < k; ++i) a[i] = 0;
   for (long i = 0; i < n; ++i)
   {
   	cin >> tmp;
   	if (tmp - 'A' < k) ++a[tmp - 'A'];
   }
   long min = a[0];
   for (long i = 1; i < k; ++i)
   {
   	if (min > a[i]) min = a[i];
   }
   cout << min * k;
   return 0;
}
    