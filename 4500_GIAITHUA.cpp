// GIAITHUA

#include <iostream>
using namespace std;
int main()
{
   long long n, sum = 1;
   cin >> n;
   for (long i = 2; i <= n; ++i) sum *= i;
   cout << sum;
   return 0;
}
    