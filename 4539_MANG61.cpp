// MANG61

#include <iostream>
using namespace std;
int main()
{
   long long n, m, dem = 0;
   cin >> n >> m;
   for (long i = 0, tmp; i < n * m; ++i) 
   { 
      cin >> tmp;
      if (tmp % 3 == 0) ++dem;
   }
   cout << dem;
   return 0;
}
    