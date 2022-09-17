// DEMUOC

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
   long long n;
   vector<long long> a, b;
   cin >> n;
   for (long long i = 2; i <= sqrt(n); ++i)
      if (n % i == 0) { b.push_back(i) ; a.push_back(n / i); }
   if (a.size() > 0 && b.size() > 0 && a[0] == b.back()) a.erase(a.begin());
   cout << n << " co "<< a.size() + b.size() + 2 << " uoc. Danh sach uoc:" << '\n' << 1 << '\n';
   for (long i = 0; i < b.size(); ++i) cout << b[i] << '\n';
   for (long i = a.size() - 1; i >= 0; --i)
      cout << a[i] << '\n';
   cout << n;
   return 0;
}
    