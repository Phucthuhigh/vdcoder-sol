// FINDK1

#include <iostream>
using namespace std;
int main()
{
   long long n, k, tmp;
   cin >> n >> k;
   for (long i = 0; i < n; ++i)
   {
      cin >> tmp;
      if (tmp == k) { cout << "YES"; return 0; }
   }
   cout << "NO";
   return 0;
}
    