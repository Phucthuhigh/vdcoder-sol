// MANG58

#include <iostream>
using namespace std;
int main()
{
   long long m, k, res;
   bool f = 0;
   cin >> m >> k;
   for (long long i = 0, tmp; i < m; ++i)
   {
      cin >> tmp;
      if (tmp == k) {f = 1; res = i + 1; break; }
   }
   if (f) cout << "CO K O VI TRI " << res;
   else cout << "KHONG CO K";
   return 0;
}
    