// FINDK2

#include <iostream>
#include <vector>
using namespace std;
int main()
{
   long long n, k, tmp;
   vector<long long> a;
   cin >> n >> k;
   for (long i = 0; i < n; ++i)
   {
      cin >> tmp;
      if (tmp == k) a.push_back(i + 1);
   }
   if (a.size() == 0) cout << "NO";
   else
   {
      cout << a.size() << '\n';
      for (long i = 0; i < a.size(); ++i) cout << a[i] << ' ';
   }
   return 0;
}
    