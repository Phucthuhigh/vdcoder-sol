// BIPHAT

#include <iostream>
using namespace std;
int main()
{
   long long n, sum = 0;
   cin >> n;
   for (long long i = 0, tmp; i < n; ++i)
   {
      cin >> tmp;
      if (tmp == 1) sum += 1;
      else sum -= 1;
   }
   if (sum < 0) sum = -sum;
   cout << sum;
   return 0;
}
    