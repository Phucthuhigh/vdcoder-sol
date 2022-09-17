// MEOVACHUOT

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
   long long a, b, c;
   cin >> a >> b >> c;
   long long kc_a = abs(a - c), kc_b = abs(b - c);
   if (kc_a == kc_b) cout << "Mouse_C";
   else
   {
      if (kc_a < kc_b) cout << "Cat_A";
      else cout << "Cat_B";
   }
   return 0;
}
    