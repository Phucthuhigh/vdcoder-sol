// XEBUYT

#include <iostream>
using namespace std;
int main()
{
   long long n, max = 0;
   cin >> n;
   for (long i = 0, tmpa, tmpb, tmp = 0; i < n; ++i) 
   {
      cin >> tmpa >> tmpb;
      tmp = tmp + tmpb - tmpa;
      if (max < tmp) max = tmp;
   }
   cout << max;
   return 0;
}
    