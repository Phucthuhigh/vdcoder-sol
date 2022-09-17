// TONGCS

#include <iostream>
using namespace std;
int main()
{
   long long n, sum = 0;
   cin >> n;
   while (n > 0)
   {
      sum = sum + (n % 10);
      n = n / 10;
   }
   cout << sum;
   return 0;
}
    