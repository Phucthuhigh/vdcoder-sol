// MANG510

#include <iostream>
#include <cmath>
using namespace std;
bool prime(long long k)
{
   if (k < 2) return 0;
   if (k == 2) return 1;
   if (k % 2 == 0) return 0;
   for (long long i = 3; i <= sqrt(k); i += 2)
      if (k % i == 0) return 0;
   return 1;
}
int main()
{
   long long n;
   bool check_p = 1;
   cin >> n;
   for (long i = 0, tmp; i < n; ++i) 
   {
      cin >> tmp;
      if (prime(tmp)) {check_p = 0; cout << i + 1 << ' ' << tmp << '\n'; }
   }
   if (check_p) cout << "KHONG CO SO NGUYEN TO";
   return 0;
}
    