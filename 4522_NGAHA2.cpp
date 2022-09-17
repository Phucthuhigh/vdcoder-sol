// NGAHA2

#include <iostream>
using namespace std;
int main()
{
   long long n, m, tmp = 0;
   cin >> n >> m;
   while (n < m)
   {
      n = n + double(n) * 0.1 + 0.5;
      ++tmp;
   }
   cout << tmp;
   return 0;
}
    