// WARNING

#include <iostream>
using namespace std;
int main()
{
   double a, b, k, t;
   cin >> a >> b >> k >> t;
   if (3 * t / (a * b) > k / 100) cout << "WARNING";
   else cout << "YES";
   return 0;
}
    