// TKNH

#include <iostream>
using namespace std;
int main()
{
   long long a, x, result = 0;
   cin >> a >> x;
   double tmp = a;
   while (tmp < x)
   {
      tmp = tmp + tmp * 0.011;
      ++result;
   }
   cout << result;
   return 0;
}
    