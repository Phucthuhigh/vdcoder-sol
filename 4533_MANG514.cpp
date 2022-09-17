// MANG514

#include <iostream>
#include <vector>
using namespace std;
int main()
{
   long long n, max = 0, min = 0;
   vector<long long> a;
   cin >> n;
   a.resize(n);
   for (long i = 0; i < n; ++i) 
   {
      cin >> a[i];
      if (a[min] > a[i]) min = i;
      if (a[max] < a[i]) max = i;
   }
   long long tmp = a[min]; a[min] = a[max]; a[max] = tmp;
   for (long i = 0; i < n; ++i) cout << a[i] << ' ';
   return 0;
}
    