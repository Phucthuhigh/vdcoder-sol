// CTC94

#include <iostream>
using namespace std;
long long sumdigit(long long n)
{
   long long result = 0;
   while (n > 0)
   {
      result = result + (n % 10);
      n /= 10;
   }
   return result;
}
int main()
{
   long long n;
   cin >> n;
   for (long long i = 0, tmp; i < n; ++i)
   {
      cin >> tmp;
      cout << tmp << ' ' << sumdigit(tmp) << '\n';
   }
   return 0;
}
    