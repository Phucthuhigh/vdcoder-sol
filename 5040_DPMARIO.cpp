// DPMARIO

#include <iostream>
#include <vector>

using namespace std;

vector<long long> f, a;
long long mod = 1000000000;

long long jump(long m)
{
   if (f[m] < 0) 
   {
      if (f[m] == -2)
      {
         if (a[m - 3] != 1)
            f[m] = (jump(m - 1) + jump(m - 2) + jump(m - 3)) % mod;
         else f[m] = (jump(m - 1) + jump(m - 2)) % mod;
      }
      else
      {
         f[m] = jump(m - 1);
      }
   }
   return f[m];
}
void set_a()
{
   if (a[1] != 2) f[1] = 1;
   if (a[2] == 0) f[2] = f[0] + f[1];
   if (a[2] == 1) f[2] = f[1];
}
int main()
{
   ios_base::sync_with_stdio(false);
   f.push_back(1);
   a.push_back(0);
   long n;
   cin >> n;
   for (long i = 1, tmp; i <= n; ++i)
   {
      cin >> tmp;
      a.push_back(tmp);
      f.push_back(tmp - 2);
   }
   a.push_back(0);
   f.push_back(-2);
   set_a();
   cout << jump(n + 1);
   return 0;
}
    