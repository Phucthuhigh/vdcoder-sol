// MANG56

#include <iostream>
using namespace std;
int main()
{
   long long n, sum = 0;
   cin >> n;
   for (long long i = 1, tmp; i <= n; i += 2)
   {
      cin >> tmp;
      if (tmp % 2 == 0) sum += tmp;
      cin >> tmp;
   }
   cout << sum;
   return 0;
}
    