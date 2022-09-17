// PHATKEO

#include <iostream>
using namespace std;
int main()
{
   long long n, sum = 0;
   cin >> n;
   for (long long i = 0, tmp = 1; i < n; ++i)
   {
      sum += tmp;
      tmp += 3;
   }
   cout << sum;
   return 0;
}
    