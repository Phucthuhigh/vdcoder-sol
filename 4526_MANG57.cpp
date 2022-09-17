// MANG57

#include <iostream>
using namespace std;
int main()
{
   long long n, d = 0;
   cin >> n;
   for (long long i = 0, tmp; i < n; ++i)
   {
      cin >> tmp;
      if (tmp > 0 && tmp % 5 == 0) ++d;
   }
   cout << d;
   return 0;
}
    