// RCSFIBO1

#include <iostream>
using namespace std;
long long fibo(long n)
{
   if (n < 2) return n;
   if (n == 2) return 1;
   long long f0 = 0, f1 = 1, f2 = 1, tmp;
   for (long i = 3; i <= n; ++i)
   {
      tmp = f1 + f2;
      f0 = f1;
      f1 = f2;
      f2 = tmp;
   }
   return f2;
}
int main()
{
   long n;
   cin >> n;
   cout << fibo(n);
   return 0;
}
    