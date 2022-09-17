// BRUFIBO

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> tich_fib;
bool bsearch(long long k)
{
   long l = 0, r = tich_fib.size() - 1, mid;
   while (l <= r)
   {
      mid = (l + r) / 2;
      if (tich_fib[mid] == k) return true;
      if (tich_fib[mid] > k) r = mid - 1;
      else l = mid + 1;
   }
   return false;
}
void set_mark()
{
   tich_fib.push_back(0);
   tich_fib.push_back(1);
   vector<long long> fib; 
   fib.push_back(0); 
   fib.push_back(1);
   long long lim = 1000000000000001;
   while (fib.back() < lim)
   {
      long long fibo = fib.back() + fib[fib.size() - 2];
      for (long i = 2; i < fib.size(); ++i)
         if (fib[i] * fibo < lim) tich_fib.push_back(fib[i] * fibo);
         else break;
      fib.push_back(fibo);
   }
   for (long i = 3; i < fib.size(); ++i) 
      if (fib[i] * fib[i] < lim) tich_fib.push_back(fib[i] * fib[i]);
      else break;
}
int main()
{
   ios_base::sync_with_stdio(false);
   
   set_mark();
   sort(tich_fib.begin(), tich_fib.end());
   
   long long n;
   cin >> n;
   for (long i = 0, tmp; i < n; ++i) 
   {
      cin >> tmp;
      if (bsearch(tmp)) cout << "YES\n";
      else cout << "NO\n";
   }
   return 0;
}
    