// SOCHAN

#include <iostream>
#include <vector>
using namespace std;
int main()
{
   long long n;
   vector<long long> a;
   cin >> n;
   for (long i = 0, tmp; i < n; ++i) 
   {
      cin >> tmp;
      if (tmp % 2 == 0) a.push_back(tmp);
   }
   cout << a.size() << '\n';
   for (long i = 0; i < a.size(); ++i)
      cout << a[i] << ' ';
   return 0;
}
    