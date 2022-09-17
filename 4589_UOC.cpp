// UOC

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
   long long n;
   vector<long long> a;
   cin >> n;
   cout << "Cac uoc so cua " << n << '\n' << 1 << '\n';
   for (long long i = 2; i <= sqrt(n); ++i)
      if (n % i == 0) { cout << i << '\n'; a.push_back(n / i); }
   for (long i = a.size() - 1; i >= 0; --i)
      cout << a[i] << '\n';
   cout << n;
   return 0;
}
    