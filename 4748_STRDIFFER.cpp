// STRDIFFER

#include <iostream>
#include <vector>
using namespace std;
int main()
{
   long long n, dem = 0;
   char k;
   cin >> n;
   if (n > 26) { cout << -1; return 0; }
   vector <long long> a('z' + 1, 0);
   for (long i = 0; i < n; ++i) 
   {
      cin >> k;
      ++a[k];
   }
   for (long i = 'a'; i <= 'z'; ++i) if (a[i] > 1) dem = dem + a[i] - 1;
   cout << dem;
   return 0;
}
    