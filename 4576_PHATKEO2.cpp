// PHATKEO2

#include <iostream>
using namespace std;
int main()
{
   long long n, k, i;
   cin >> n >> k;
   for (i = 0; 3 * i + 1 <= k && i < n; ++i) k = k - (3 * i + 1);
   cout << i;
   return 0;
}
    