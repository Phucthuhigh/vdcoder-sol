// DPGAME

#include <iostream>
#include <vector>

using namespace std;

vector<long long> f(100001, -1);
long long mod = 25071987;

long long lat_gach(long m)
{
   if (f[m] == -1) f[m] = (lat_gach(m - 1) + lat_gach(m - 2)) % mod;
   return f[m];
}
int main()
{
   long n, k;
   cin >> n >> k;
   for (long i = 0, tmp; i < k; ++i)
   {
      cin >> tmp;
      f[tmp] = 0;
   }
   
   f[1] = 1;
   if (f[2] != 0) f[2] = 1;
   cout << lat_gach(n);
   return 0;
}
    