// TOADO

#include <iostream>
using namespace std;
int main()
{
   double x, y, u, v, a, b;
   cin >> x >> y >> u >> v;
   a = x * x + y * y;
   b = u * u + v * v;
   if (a == b) cout << "BANG NHAU";
   else
   {
   	if (a < b) cout << "A";
   	else cout << "B"; 
   }
   return 0;
}
    