// CTC93

#include <iostream>
using namespace std;
long long fact(long long n)
{
   long long result = 1;
   for (long long i = 2; i <= n; ++i)
      result *= i;
   return result;
}
int main()
{
   long long n;
   cin >> n;
   for (long long i = 0, tmp; i < n; ++i)
   {
      cin >> tmp;
      cout << fact(tmp) << '\n';
   }
   return 0;
}
    