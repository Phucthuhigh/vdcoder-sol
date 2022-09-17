// TONGLE

#include <iostream>
using namespace std;
int main()
{
   long long n, sum = 0;
   cin >> n;
   for (long long i = 1; i <= n; i += 2) sum += i;
   cout << sum;
   return 0;
}
    